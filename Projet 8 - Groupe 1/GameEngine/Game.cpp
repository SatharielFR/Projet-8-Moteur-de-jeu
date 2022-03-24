#include "Game.h"
#include "RailManager.h"

#pragma region GlobalVariables
    HINSTANCE hInst;                                // instance actuelle
    WCHAR szTitle[MAX_LOADSTRING];                  // Texte de la barre de titre
    WCHAR szWindowClass[MAX_LOADSTRING];            // nom de la classe de fenêtre principale
#pragma endregion

#pragma region WindowsEntry
    // the entry point for any Windows program
    int WINAPI WinMain( HINSTANCE hInstance,
                        HINSTANCE hPrevInstance,
                        LPSTR lpCmdLine,
                        int nCmdShow)
    {
        HWND hWnd;
        WNDCLASSEX wc;
        ZeroMemory(&wc, sizeof(WNDCLASSEX));
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.lpszClassName = L"WindowClass";
        RegisterClassEx(&wc);
        hWnd = CreateWindowEx(NULL, L"WindowClass", L"Projet 8 : Moteur de jeu",
                              WS_OVERLAPPEDWINDOW, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                              NULL, NULL, hInstance, NULL);
        ShowWindow(hWnd, nCmdShow);

        // Set up and initialize Direct3D
        g_game = new Game(hWnd);

        // Enter the main loop:
        MSG msg;
        g_game->m_bIsRunning = true;
        while (g_game->m_bIsRunning == true)
        {
            g_game->Update();
        
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                if (msg.message == WM_QUIT)
                {
                    g_game->m_bIsRunning = false;
                    break;
                }
            }

        }
        g_game->Close();
        return msg.wParam;
    }

    // this is the main message handler for the program
    LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
            case WM_MOUSEMOVE:
            {
//                Debug::s_inst->ScreenLog("MouseMove");
                //OnMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
                return 0;
            }
            case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            } 
            break;
        }

        return DefWindowProc(hWnd, message, wParam, lParam);
    }
#pragma endregion

#pragma region GameFunctions

    Game::Game(HWND hWnd)
    {

        g_game = this;

        //Create Engine
        m_engine = new Engine(hWnd);

        //Create a map for the Menu
        Scene* sceneMenu = new Scene("Menu");
        m_engine->GetSceneMananger()->AddScene(sceneMenu);
//        m_engine->GetSceneMananger()->OpenScene("Menu");

        //Create a map for the game
        Scene* sceneMain = new Scene("Main");
        m_engine->GetSceneMananger()->AddScene(sceneMain);
        m_engine->GetSceneMananger()->OpenScene("Main");

        //Create Cube For Test Purpose
        Entity* l_entitySkybox = new Entity();
        sceneMain->AddEntity(l_entitySkybox);
        MeshComponent* l_meshComponentSkybox= new MeshComponent();
        l_meshComponentSkybox->SetMeshAndTexturePath("..\\Ressources\\Skybox.x");
        l_entitySkybox->AddComponent(l_meshComponentSkybox);

        //Create Tiger For Test Purpose
        Entity* l_entityTiger = new Entity();
        sceneMain->AddEntity(l_entityTiger);
        MeshComponent* l_meshComponentTiger = new MeshComponent();
        l_meshComponentTiger->SetMeshAndTexturePath("..\\Ressources\\Tiger.x");
        l_entityTiger->AddComponent(l_meshComponentTiger);

        //Create Cube For Test Purpose
        Entity* l_entityCube = new Entity();
        sceneMain->AddEntity(l_entityCube);
        MeshComponent* l_meshComponentCube = new MeshComponent();
        RigidbodyComponent* l_rigidbodycomponent = new RigidbodyComponent();
        l_meshComponentCube->SetMeshAndTexturePath("..\\Ressources\\Cube.x");
        l_entityCube->AddComponent(l_meshComponentCube);
        l_entityCube->AddComponent(l_rigidbodycomponent);

        //Create Ground
        //Entity* l_entityGround = new Entity();
        //MeshComponent* l_meshComponentGround = new MeshComponent();
        //l_meshComponentCube->SetMeshAndTexturePath("..\\Ressources\\Cube.x");
        //sceneMain->AddEntity(l_entityGround);

        //Create Camera
        m_entityCamera = new Entity();
        sceneMain->AddEntity(m_entityCamera);
        m_cameraComponent = new CameraComponent();
        m_entityCamera->AddComponent(m_cameraComponent);

        //Create Target
        Entity* l_entityTarget= new Entity();
        sceneMain->AddEntity(l_entityTarget);
        MeshComponent* l_meshComponentTarget= new MeshComponent();
        l_meshComponentTarget->SetMeshAndTexturePath("..\\Ressources\\Target.x");
        l_entityTarget->AddComponent(l_meshComponentTarget);

        //Create Rail
        //Entity* l_entityRails = new Entity();
        //sceneMain->AddEntity(l_entityRails);
        //MeshComponent* l_meshComponentRails = new MeshComponent();
        //l_meshComponentRails->SetMeshAndTexturePath("..\\Ressources\\rail.x");
        //l_entityRails->AddComponent(l_meshComponentRails);

        m_railManager = new RailManager();

        //for (int i = 0; i < m_nbRailsToSPawn; i++)
        //{
        //    float x;
        //    float y;
        //}




        //Start Game
        g_game->Begin();

        //!!! Faire les Mooves APRES le Begin !!!
        
        //Cam
        m_entityCamera->transform->m_transform->SetPosition(0.0f, 0.0f, 10.0f);
        //Tigre
        l_entityTiger->transform->m_transform->Move(0.0f, 0.0f, 0.0f);
        //Cube
        l_entityCube->transform->m_transform->Move(0.0f, 0.0f, 0.0f);
        l_entityCube->transform->m_transform->Rotate(45.0f, 45.0f, 0.0f);
        l_entityCube->transform->m_transform->Scaling(0.01f, 0.01f, 0.01f);
        //Skybox
        l_entitySkybox->transform->m_transform->Scaling(1000.f, 1000.f, 1000.f);
        //Target
        l_entityTarget->transform->m_transform->SetPosition(0.0f, 5.0f, 0.0f);
        l_entityTarget->transform->m_transform->ScalingUniforme(0.01f);
        l_entityTarget->transform->m_transform->RotateAngle( 90.0f,0.f,0.f);
    }

    void Game::Begin()
    {
        Debug::s_inst->ScreenLog("Game Begin");        //Debug
        m_engine->Begin();
        m_railManager->CreateRails(m_engine->GetSceneMananger()->GetCurrentScene());
    }


    void Game::Update()
    {
        m_engine->Update();
        UpdateInputs();
        UpdateMouseInputs();
        UpdateCameraPosition();   
    }

    void Game::Close()
    {
        // clean up DirectX and COM
        g_game->m_engine->Close();
    }

    //Detect Inputs
    void Game::UpdateInputs()
    {
        float l_fDebugDuration = 0.01f;
        //Forward inputs
        if (GetKeyState('Z') & 0x8000)
        {
            _fForwardValue = -1;
        }
        else if (GetKeyState('S') & 0x8000)
        {
            _fForwardValue = 1;
        }
        else
        {
            _fForwardValue = 0;
        }

        //Horizontal inputs
        if (GetKeyState('D') & 0x8000)
        {
            _fHorizontalValue = -1;
        }
        else if (GetKeyState('Q') & 0x8000)
        {
            _fHorizontalValue = 1;
        }
        else
        {
            _fHorizontalValue = 0;
        }

        //Echap
        if (GetKeyState(VK_ESCAPE) & 0x8000)
        {
            //Unlock Mouse Position
            m_bCursorIsLocked = false;
        }
    }


    void Game::UpdateMouseInputs()
    {
        POINT point;
        if (GetCursorPos(&point))
        {
            if (m_bCursorIsLocked)
            {
                int l_nbAnchorPositionX = 0, l_nbAnchorPositionY = 0;

                RECT rect;
                if (GetWindowRect(m_engine->getHwnd(), &rect))
                {
                    l_nbAnchorPositionX =  rect.left;
                    l_nbAnchorPositionY = rect.top;
                }

                int l_nbScreenCenterX = (SCREEN_WIDTH / 2 ) + l_nbAnchorPositionX;
                int l_nbScreenCenterY = (SCREEN_HEIGHT / 2) + l_nbAnchorPositionY;

                l_MouseMovementX = point.x - l_nbScreenCenterX;
                l_MouseMovementY = point.y - l_nbScreenCenterY;

                _nbMouseX = point.x;
                _nbMouseY = point.y;

                SetCursorPos(l_nbScreenCenterX, l_nbScreenCenterY);
            }
            else
            {
                l_MouseMovementX = point.x - _nbMouseX;
                l_MouseMovementY = point.y - _nbMouseY;

                _nbMouseX = point.x;
                _nbMouseY = point.y;
            }
        }
    }

    void Game::UpdateCameraPosition()
    {
        m_entityCamera->transform->m_transform->Move(   _fHorizontalValue * _fSpeed * Timer::s_inst->GetDeltaTime(),
                                                        0 ,
                                                        _fForwardValue * _fSpeed * Timer::s_inst->GetDeltaTime());
        

        m_entityCamera->transform->m_transform->ClearRotation();

        static float l_fYaw = 0.f;
        static float l_fPitch = 0.f;

        float l_fCameraSensibility = 0.5f;
        l_fPitch += l_MouseMovementY * (D3DX_PI / 180.f) * l_fCameraSensibility;
        l_fYaw += l_MouseMovementX * (D3DX_PI / 180.f) * l_fCameraSensibility;

        l_fPitch = std::clamp(l_fPitch, -D3DX_PI / 3, D3DX_PI / 3);
        //l_fYaw = std::clamp(l_fYaw, -D3DX_PI / 3, D3DX_PI / 3);
       
        m_entityCamera->transform->m_transform->Rotate(l_fPitch, l_fYaw, 0);
    }

#pragma endregion