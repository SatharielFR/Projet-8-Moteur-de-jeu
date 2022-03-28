#include "pch.h"
#include "framework.h"
//using namespace Interface;

LPDIRECT3DDEVICE9 Engine::d3ddev = nullptr;
float Engine::gravity = 9.80f;

//Constructeur
Engine::Engine(HWND hWnd)
{
    _hWnd = hWnd;
    InitD3D(_hWnd);
    Init();
}

//Init all engine values
void Engine::Init()
{
    _sceneManager = new SceneManager();
    _debug = new Debug(&d3ddev);
    _timer = new Timer();
    _fLastCheckFpsTime = _timer->GetSystemTimeEx();
}

void Engine::Begin()
{
    if (_sceneManager)
    {
        _sceneManager->Begin();
    }
}

void Engine::Update()
{
    if (_timer)
    {
        //UpdateTime and only update the game if the time elapsed is long enough
        if (_timer->UpdateTime())
        {
            //UpdatePhysique
            RenderFrame();
            //Update FPS
            if (_timer->GetSystemTimeEx() > _fLastCheckFpsTime + 1.0f)
            {
                _nbFps = _nbFpsCount;
                _fLastCheckFpsTime = _timer->GetSystemTimeEx();
                _nbFpsCount = 1;

            }
            else
            {
                _nbFpsCount++;
            }
        }
    }
}

void Engine::Close()
{
    CleanD3D();
}

// this function initializes and prepares Direct3D for use
void Engine::InitD3D(HWND hWnd)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

    D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information
    ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
    d3dpp.Windowed = TRUE;    // FALSE - program windowed, not fullscreen
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
    d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
    d3dpp.BackBufferWidth = SCREEN_WIDTH;    // set the width of the buffer
    d3dpp.BackBufferHeight = SCREEN_HEIGHT;    // set the height of the buffer
    d3dpp.EnableAutoDepthStencil = TRUE;    // automatically run the z-buffer for us
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;    // 16-bit pixel format for the z-buffer

    // create a device class using this information and information from the d3dpp stuct
    d3d->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &d3ddev);
    InitGraphics();    // call the function to initialize the triangle

    d3ddev->SetRenderState(D3DRS_LIGHTING, FALSE);    // turn off the 3D lighting
    d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);    // both sides of the triangles
//    d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);    // On the side of the triangles normal
//    d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);    // On the side of the triangles normal
    d3ddev->SetRenderState(D3DRS_ZENABLE, TRUE);    // turn on the z-buffer
}

D3DMATERIAL9 Engine::CreateTestMaterial() {
    D3DMATERIAL9 mtrl;
    ZeroMemory(&mtrl, sizeof(mtrl));
    mtrl.Emissive.r = 0.0f;
    mtrl.Emissive.g = 0.75f;
    mtrl.Emissive.b = 0.0f;
    mtrl.Emissive.a = 0.0f;
    d3ddev->SetMaterial(&mtrl);
    d3ddev->SetRenderState(D3DRS_EMISSIVEMATERIALSOURCE, D3DMCS_MATERIAL);
    return mtrl;
}

// this is the function that puts the 3D models into video RAM
void Engine::InitGraphics(void)
{
    //Use for draw a complex figure with vertex and indices
}

// this is the function used to render a single frame
void Engine::RenderFrame(void)
{
    D3DCOLOR ClearColor = D3DCOLOR_XRGB(255, 0, 0);

    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET| D3DCLEAR_ZBUFFER, _ClearColor, 1.0f, 0);
    d3ddev->BeginScene();

    // Render Game
    _sceneManager->UpdateScene();
    _debug->UpdateScreenLogs();

    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    static float index = 0.0f; index += 0.05f * Timer::s_inst->GetDeltaTime(); // an ever-increasing float value

    //Get the list of MeshComponents to render from the scene&
    if (_sceneManager->GetCurrentScene())
    {
        //For each Components of the scene
        list<Entity*> l_entities = _sceneManager->GetCurrentScene()->GetEntities();
        for (Entity* l_currentEntity: l_entities)
        {
            //If there is a Mesh Component
            MeshComponent* l_meshComponent = (MeshComponent*)l_currentEntity->GetComponentByType<MeshComponent>();
            TransformComponent* l_transformComponent = (TransformComponent*)l_currentEntity->GetComponentByType<TransformComponent>();
            if (l_meshComponent != nullptr)
            {
                //making string to lpwstr for CreateTextureFromFile
                std::string myString = l_meshComponent->GetMeshAndTexturePath();
                wstring stemp = wstring(myString.begin(), myString.end());
                LPCWSTR fullPath = stemp.c_str();
                l_meshComponent->LoadMesh(fullPath, d3ddev);

                //setting transform and DRAWING mesh
                Transform* tr = l_transformComponent->m_transform;

                if (tr != nullptr)
                {
                    d3ddev->SetTransform(D3DTS_WORLD, &tr->m_matrix);
                    for (DWORD i = 0; i < l_meshComponent->GetNumMaterials(); i++)
                    {
                        // Set the material and texture for this subset
                        d3ddev->SetMaterial(&l_meshComponent->GetMeshMaterials()[i]);
                        d3ddev->SetTexture(0, l_meshComponent->GetMeshTextures()[i]);
                        // Draw the mesh subset
                        l_meshComponent->GetMesh()->DrawSubset(i);
                    }
                }
            }
        }

        //draw HUD on top
        _HudToDraw = _sceneManager->GetCurrentScene()->GetHUD();
        if (_HudToDraw != nullptr) 
        {
            _HudToDraw->UpdateHUD(d3ddev);
        }
    }

    d3ddev->EndScene();

    d3ddev->Present(NULL, NULL, NULL, NULL);
}

// this is the function that cleans up Direct3D and COM
void Engine::CleanD3D(void)
{
    d3ddev->Release();    // close and release the 3D device
    d3d->Release();    // close and release Direct3D
}


