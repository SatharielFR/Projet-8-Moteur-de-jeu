#include "pch.h"
#include "framework.h"
//using namespace Interface;

LPDIRECT3DDEVICE9 Engine::d3ddev = nullptr;
float Engine::gravity = 9.8f;

//Constructeur
Engine::Engine(HWND hWnd)
{
    _hWnd = hWnd;
    InitD3D(_hWnd);
    Init();
}

Engine::~Engine()
{
    delete _hWnd;
    delete _sceneManager;
    delete _debug;
    delete _timer;
    delete _HudToDraw;
    delete _sceneCurrent;
    delete _scenePrevious;

    ConsoleLog("Engine");
}



//Init all engine values
void Engine::Init()
{
    ClearColor = D3DCOLOR_XRGB(255, 0, 0);
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
            CollisionCheck();
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
            _timer->UpdateDeltaTime();
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
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET| D3DCLEAR_ZBUFFER, _ClearColor, 1.0f, 0);
    d3ddev->BeginScene();

    // Render Game
    _sceneManager->UpdateScene();

    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    //Get the CurrentScene
    _sceneCurrent = _sceneManager->GetCurrentScene();

    //Get the list of MeshComponents to render from the scene
    if (_sceneCurrent)
    {
        //if the scene has changedn 
        if (_sceneCurrent != _scenePrevious)
        {
            //update the list of entities
            l_entities = _sceneCurrent->GetEntities();
            //Update HUD
            _HudToDraw = _sceneManager->GetCurrentScene()->GetHUD();
        }

        //For each Components of the scene
        for (Entity* l_currentEntity: l_entities)
        {
            //If there is a Mesh Component
            MeshComponent* l_meshComponent = (MeshComponent*)l_currentEntity->GetComponentByType<MeshComponent>();
            if (l_meshComponent != nullptr)
            {
                if (!l_meshComponent->IsMeshLoaded())
                {
                    //making string to lpwstr for CreateTextureFromFile
                    std::string myString = l_meshComponent->GetMeshAndTexturePath();
                    wstring stemp = wstring(myString.begin(), myString.end());
                    LPCWSTR fullPath = stemp.c_str();
                    l_meshComponent->LoadMesh(fullPath, d3ddev);
                }

                //setting transform and DRAWING mesh
                Transform* tr = l_currentEntity->transform->m_transform;

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
                    tr = nullptr;
                }

                delete tr;
                l_meshComponent = nullptr;
                delete l_meshComponent;
                l_currentEntity = nullptr;
                delete l_currentEntity;
            }
        }

        //draw HUD on top
        if (_HudToDraw != nullptr) 
        {
            _HudToDraw->UpdateHUD(d3ddev);
        }


        _scenePrevious = _sceneCurrent;
    }

    _debug->UpdateScreenLogs(); //Draw ScreenLogs on top

    d3ddev->EndScene();

    d3ddev->Present(NULL, NULL, NULL, NULL);
}

// this is the function that cleans up Direct3D and COM
void Engine::CleanD3D(void)
{
    d3ddev->Release();    // close and release the 3D device
    d3d->Release();    // close and release Direct3D
}

void Engine::CollisionCheck()
{
    if (GetSceneMananger()->GetCurrentScene()->GetSceneName() == "Game")
    {
        //For each Components of the scene
        std::vector<Entity*> l_entities = GetSceneMananger()->GetCurrentScene()->GetEntities();
        for (auto i = l_entities.begin(); i != l_entities.end(); i++)
        {
            RigidbodyComponent* firstRb = (RigidbodyComponent*)(*i)->GetComponentByType<RigidbodyComponent>();

            if (firstRb != nullptr)
            {
                for (auto j = l_entities.begin(); j != l_entities.end(); j++)
                {
                    RigidbodyComponent* secondRb = (RigidbodyComponent*)(*j)->GetComponentByType<RigidbodyComponent>();

                    if (secondRb != nullptr && secondRb != firstRb)
                    {
                        Collision(firstRb, secondRb);
                    }
                }
            }
        }
    }
}

void Engine::Collision(RigidbodyComponent* rb1, RigidbodyComponent* rb2)
{
    D3DXVECTOR3 pos1 = rb1->GetParent()->transform->m_transform->m_vPos;
    D3DXVECTOR3 pos2 = rb2->GetParent()->transform->m_transform->m_vPos;

    bool result = std::pow(pos1.x - pos2.x, 2) +
                  std::pow(pos1.y - pos2.y, 2) +
                  std::pow(pos1.z - pos2.z, 2)
                  <= rb1->radius + rb2->radius;
    
    if(result)
    {
        collisionResult.push_back(new CollisionResult(result, rb1, rb2));
    }
}

void Engine::RemoveCollisionResult(CollisionResult* CollsionToRem)
{
    if (CollsionToRem == nullptr || collisionResult.size() < 1) { return; }

    auto i = std::find(collisionResult.begin(), collisionResult.end(), CollsionToRem);

    if (i == collisionResult.end()) { return; }

    collisionResult.erase(i);
    delete CollsionToRem;
}


