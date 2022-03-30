#include "Game.h"
//Hud
#include "GameHud.h"
#include "MenuHud.h"
#include "SplashHud.h"
//Gameplay
#include "RailManager.h"
#include "Cart.h"
#include "Player.h"
#include "TargetSpawner.h"

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
        hWnd = CreateWindowEx(  NULL, L"WindowClass", L"Projet 8 : Moteur de jeu",
                                WS_POPUP, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
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

        //Create a map for the Splash
        Scene* sceneSplash = new Scene("Splash");
        m_engine->GetSceneMananger()->AddScene(sceneSplash);
//        m_engine->GetSceneMananger()->OpenScene("Splash");

        //Create Menu Splash
        m_splashHud = new SplashHud(sceneSplash, m_engine);

        //Create a map for the Menu
        Scene* sceneMenu = new Scene("Menu");
        m_engine->GetSceneMananger()->AddScene(sceneMenu);
//        m_engine->GetSceneMananger()->OpenScene("Menu");

        //Create Menu HUD
        m_menuHud = new MenuHud(sceneMenu, m_engine);

        //Create a map for the game
        m_sceneGame = new Scene("Game");
        m_engine->GetSceneMananger()->AddScene(m_sceneGame);
        m_engine->GetSceneMananger()->OpenScene("Game");
        srand((int)Timer::s_inst->GetSystemTimeEx());

        //Create Game HUD
        m_gameHud = new GameHud(m_sceneGame, m_engine);

        //Create Skybox
        Entity* l_entitySkybox = new Entity();
        m_sceneGame->AddEntity(l_entitySkybox);
        MeshComponent* l_meshComponentSkybox= new MeshComponent();
        l_meshComponentSkybox->SetMeshAndTexturePath("..\\Ressources\\Skybox.x");
        l_entitySkybox->AddComponent(l_meshComponentSkybox);
        l_entitySkybox->transform->m_transform->Scaling(1000.f, 1000.f, 1000.f);

        //Create Camera
        m_entityCamera = new Entity();
        m_sceneGame->AddEntity(m_entityCamera);
        m_cameraComponent = new CameraComponent();
        m_entityCamera->AddComponent(m_cameraComponent);
        m_entityCamera->transform->m_transform->SetPosition(0.0f, 3.0f, 10.0f);

        //Create Target
        Entity* l_entityTarget= new Entity();
        m_sceneGame->AddEntity(l_entityTarget);
        MeshComponent* l_meshComponentTarget= new MeshComponent();
        l_meshComponentTarget->SetMeshAndTexturePath("..\\Ressources\\Target.x");
        l_entityTarget->AddComponent(l_meshComponentTarget);
        RigidbodyComponent* l_rigidbodyTarget = new RigidbodyComponent();
        l_rigidbodyTarget->radius = 5;
        l_entityTarget->AddComponent(l_rigidbodyTarget);
        l_entityTarget->transform->m_transform->SetPosition(0.0f, 5.0f, 0.0f);
        l_entityTarget->transform->m_transform->ScalingUniforme(0.01f);
        l_entityTarget->transform->m_transform->RotateAngle(90.0f, 0.f, 0.f);

        //Create Ground
        Entity* l_entityGround = new Entity();
        m_sceneGame->AddEntity(l_entityGround);
        MeshComponent* l_meshComponentGround = new MeshComponent();
        l_meshComponentGround->SetMeshAndTexturePath("..\\Ressources\\Plane.x");
        l_entityGround->AddComponent(l_meshComponentGround);
        l_entityGround->transform->m_transform->ScalingUniforme(10.0f);
        l_entityGround->transform->m_transform->SetPosition(0.0f, 0.0f, 0.0f);
        l_entityGround->transform->m_transform->RotateAngle(180.0f, 0.f, 0.f);

        //Create Rail
        m_railManager = new RailManager();

        //Create Cart
        m_cart = new Cart(m_sceneGame, m_railManager);

        //Create Target Spawner
        m_targetSpawner = new TargetSpawner(m_sceneGame, m_railManager);

        //Create Player
        m_player = new Player(m_sceneGame);

        //Start Game
        g_game->Begin();
    }

    void Game::Begin()
    {
        ShowCursor(false);
        Debug::s_inst->ScreenLog("Game Begin", 5.f);        //Debug
        m_engine->Begin();
        m_railManager->CreateRails(m_sceneGame);
        m_targetSpawner->SpawnTargets();
    }

    void Game::Update()
    {
        m_engine->Update();
        if (m_engine->GetSceneMananger()->GetSceneByName("Splash")->GetIsRunning())
        {
            m_splashHud->Update();
        }
        if (m_engine->GetSceneMananger()->GetSceneByName("Menu")->GetIsRunning())
        {
            m_menuHud->Update();
        }
        //if (m_sceneMain->GetHasStarted())
        if(m_engine->GetSceneMananger()->GetSceneByName("Game")->GetIsRunning())
        {
            m_gameHud->Update();
            m_cart->Update();
            m_cart->SetForwardValue(_fForwardValue);
            m_player->l_player->transform->m_transform->SetPosition(m_cart->m_entityCart->transform->m_transform->m_vPos.x,
                                                                    m_cart->m_entityCart->transform->m_transform->m_vPos.y + _fCameraOffset,
                                                                    m_cart->m_entityCart->transform->m_transform->m_vPos.z);
            m_player->Update(m_sceneGame);
            UpdateInputs();
            UpdateMouseInputs();
            UpdateCameraTransfrom();
        }
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
            _fForwardValue = 1;
            if (GetKeyState(VK_LSHIFT))
            {
                _fForwardValue = 2;
            }
        }
        else if (GetKeyState('S') & 0x8000)
        {
            _fForwardValue = -1;
            if (GetKeyState(VK_LSHIFT))
            {
                _fForwardValue = -2;
            }
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
            ShowCursor(true);

            PostQuitMessage(WM_CLOSE);
//            PostQuitMessage(0); //Close window
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

    void Game::UpdateCameraTransfrom()
    {
        //Update Rotation
        //m_entityCamera->transform->m_transform->Move(   _fHorizontalValue * _fSpeed * Timer::s_inst->GetDeltaTime(),
        //                                                0 ,
        //                                                _fForwardValue * _fSpeed * Timer::s_inst->GetDeltaTime());


        m_entityCamera->transform->m_transform->SetPosition(    m_cart->GetCartPosition().x, 
                                                                m_cart->GetCartPosition().y + _fCameraOffset,
                                                                m_cart->GetCartPosition().z);
        
        //Update Rotation
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