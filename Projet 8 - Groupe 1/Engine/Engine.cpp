#include "pch.h"
#include "framework.h"

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
    // create the vertices using the CUSTOMVERTEX struct
    CUSTOMVERTEX vertices[] =
    {
        /*{ -3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 0, 255), },
        { 3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { -3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(255, 0, 0), },
        { 3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 255), },*/

        // Vertex for cube 
      //{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },    // vertex 0
      //{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 0), },     // vertex 1
      //{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },   // 2
      //{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },  // 3
      //{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },     // ...
      //{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 0, 0), },
      //{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
      //{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 255), },

      // Vertex for pyramide
        // // base
        { -3.0f, 0.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { 3.0f, 0.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        { -3.0f, 0.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },
        { 3.0f, 0.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },

        //// top
        { 0.0f, 5.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },

        // Vertex the Hypercraft
        // fuselage
        //{ 3.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
        //{ 0.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        //{ 0.0f, 0.0f, 10.0f, D3DCOLOR_XRGB(255, 0, 0), },
        //{ -3.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 255), },

        //// left gun
        //{ 3.2f, -1.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        //{ 3.2f, -1.0f, 11.0f, D3DCOLOR_XRGB(0, 255, 0), },
        //{ 2.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(255, 0, 0), },

        //// right gun
        //{ -3.2f, -1.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        //{ -3.2f, -1.0f, 11.0f, D3DCOLOR_XRGB(0, 255, 0), },
        //{ -2.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(255, 0, 0), },

    };

    //create a vertex buffer interface called v_buffer
    d3ddev->CreateVertexBuffer(5 * sizeof(CUSTOMVERTEX),
        0,
        CUSTOMFVF,
        D3DPOOL_MANAGED,
        &v_buffer,
        NULL);

    VOID* pVoid;    // a void pointer

    // lock v_buffer and load the vertices into it
    v_buffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, vertices, sizeof(vertices));
    v_buffer->Unlock();


    // create the indices using an int array
    short indices[] =
    {
        // indice for cube
        //0, 1, 2,    // side 1
        //2, 1, 3,
        //4, 0, 6,    // side 2
        //6, 0, 2,
        //7, 5, 6,    // side 3
        //6, 5, 4,
        //3, 1, 7,    // side 4
        //7, 1, 5,
        //4, 5, 0,    // side 5
        //0, 5, 1,
        //3, 7, 2,    // side 6
        //2, 7, 6,

        // indice for pyramide
        0, 2, 1,    // base
        1, 2, 3,
        0, 1, 4,    // sides
        1, 3, 4,
        3, 2, 4,
        2, 0, 4,

        // indice the hypercraft
        //0, 1, 2,    // fuselage
        //2, 1, 3,
        //3, 1, 0,
        //0, 2, 3,
        //4, 5, 6,    // wings
        //7, 8, 9,

    };


    d3ddev->CreateIndexBuffer(18 * sizeof(short),    // 3 per triangle, 12 triangles
        0,
        D3DFMT_INDEX16,
        D3DPOOL_MANAGED,
        &i_buffer,
        NULL
    );

    // lock i_buffer and load the indices into it
    i_buffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, indices, sizeof(indices));
    i_buffer->Unlock();
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



    //// set the view transform
    D3DXMatrixLookAtLH(&matView,
        &vecCamPosition,   // the camera position
        &vecLookAtPosition,    // the look-at position
        &vecUpDirection);    // the up direction
    d3ddev->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView

    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
        D3DXToRadian(45),    // the horizontal field of view
        (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT, // aspect ratio
        1.0f,    // the near view-plane
        100.0f);    // the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);     // set the projection


    // select the vertex buffer to display
    d3ddev->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
    d3ddev->SetIndices(i_buffer);

    static float index = 0.0f; index += 0.05f * Timer::s_inst->GetDeltaTime(); // an ever-increasing float value

    //
    //Transform test;
    //test.Rotate(index, index, index);
    ////test.Scaling(0.5f, 0.5f, 0.5f);
    //test.ScalingUniforme(1.5f);
    ////test.Move(1.0f,5.0f,1.0f);
    //test.MoveUniforme(-2.0f);
    ////test.SetPosition(2.0f,1.0f,2.0f);


    //// tell Direct3D about each world transform, and then draw another triangle
    //d3ddev->SetTransform(D3DTS_WORLD, &test.m_matrix);

    // draw the cube
   // d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

    // draw the pyramid
   // d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 5, 0, 6);

    // draw the Hypercraft
    //d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 10, 0, 6);

    //d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
    // d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);


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
                LPCTSTR l_pathName = L"..\\Ressources\\tiger.x"; //TODO : MeshComponent.GetPath()
                l_meshComponent->LoadMesh(l_pathName, d3ddev);

                //setting transform and DRAWING mesh
                Transform* tr;
                //TODO : FIX IT
                if (/*l_transformComponent != nullptr && l_transformComponent->m_transform != nullptr*/ false)
                {
                    //Doesnt Work
                    tr = l_transformComponent->m_transform;
                    tr->Move(0.0f, 0.0f, 0.0f);
                    tr->UpdateMatrix();
                    tr->ScalingUniforme(1.0f);
                    tr->Rotate(index, 0.0f, index);
                }
                else
                {
                    //Work
                    tr = new Transform();
                    tr->Move(0.0f, 0.0f, 0.0f);
                    tr->UpdateMatrix();
                    tr->ScalingUniforme(1.0f);
                    tr->Rotate(index, 0.0f, index);                 
                }

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
    }

    //list<MeshComponent*> l_listLeshComponents = _sceneManager->GetMeshComponents();

    //// scene manager => get current scene => get tous les mesh (liste) => draw chaque mesh
    //for (MeshComponent * l_currentMeshComponent: l_listLeshComponents)
    //{
    //    LPCTSTR l_pathName = L"..\\Ressources\\tiger.x";
    //    l_currentMeshComponent->LoadMesh(l_pathName, d3ddev);

    //    //setting transform and DRAWING mesh
    //    Transform tr;
    //    tr.m_vPos.x = 200.0f;
    //    tr.m_vPos.z = 200.0f;
    //    tr.UpdateMatrix();
    //    tr.ScalingUniforme(1.0f);
    //    tr.Rotate(index, 0.0f, index);

    //    d3ddev->SetTransform(D3DTS_WORLD, &tr.m_matrix);
    //    for (DWORD i = 0; i < l_currentMeshComponent->GetNumMaterials(); i++)
    //    {
    //        // Set the material and texture for this subset
    //        d3ddev->SetMaterial(&l_currentMeshComponent->GetMeshMaterials()[i]);
    //        d3ddev->SetTexture(0, l_currentMeshComponent->GetMeshTextures()[i]);
    //        // Draw the mesh subset
    //        l_currentMeshComponent->GetMesh()->DrawSubset(i);
    //    }
    //}

    //Save : OLD tigger Display

    //MeshComponent meshComp;
    //LPCTSTR l_pathName = L"..\\Ressources\\tiger.x";
    //meshComp.LoadMesh(l_pathName, d3ddev);
    ////meshComp.LoadMesh(L"..\\Ressources\\tiger.x", d3ddev);

    ////setting transform and DRAWING mesh
    //Transform tr;
    //tr.m_vPos.x = 200.0f;
    //tr.m_vPos.z = 200.0f;
    //tr.UpdateMatrix();
    //tr.ScalingUniforme(1.0f);
    //tr.Rotate(index, 0.0f, index);
    //d3ddev->SetTransform(D3DTS_WORLD, &tr.m_matrix);
    //for (DWORD i = 0; i < meshComp.GetNumMaterials(); i++)
    //{
    //    // Set the material and texture for this subset
    //    d3ddev->SetMaterial(&meshComp.GetMeshMaterials()[i]);
    //    d3ddev->SetTexture(0, meshComp.GetMeshTextures()[i]);
    //    // Draw the mesh subset
    //    meshComp.GetMesh()->DrawSubset(i);
    //}

    d3ddev->EndScene();

    d3ddev->Present(NULL, NULL, NULL, NULL);
}

// this is the function that cleans up Direct3D and COM
void Engine::CleanD3D(void)
{
    v_buffer->Release();    // close and release the vertex buffer
    d3ddev->Release();    // close and release the 3D device
    d3d->Release();    // close and release Direct3D
}


