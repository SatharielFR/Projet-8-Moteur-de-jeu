#include "Game.h"


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
        hWnd = CreateWindowEx(NULL, L"WindowClass", L"Our Direct3D Program",
                              WS_OVERLAPPEDWINDOW, 300, 300, SCREEN_WIDTH, SCREEN_HEIGHT,
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

        //Create a map for the game
        Scene* sceneMain = new Scene("Main");
        m_engine->GetSceneMananger()->AddScene(sceneMain);
        m_engine->GetSceneMananger()->OpenScene("Main");

        //Create Tigger For Test Purpose
        Entity* l_entityTigger = new Entity();
        sceneMain->AddEntity(l_entityTigger);
        MeshComponent* l_meshComponentTigger = new MeshComponent();
        l_meshComponentTigger->SetMeshAndTexturePath("..\\Ressources\\Tiger.x");
        l_entityTigger->AddComponent(l_meshComponentTigger);


        //Create Cube For Test Purpose
        Entity* l_entityCube = new Entity();
        sceneMain->AddEntity(l_entityCube);
        MeshComponent* l_meshComponentCube = new MeshComponent();
        l_meshComponentCube->SetMeshAndTexturePath("..\\Ressources\\Cube.x");
        l_entityCube->AddComponent(l_meshComponentCube);

        //Start Game
        g_game->Begin();

        //!!! Faire les Mooves APRES le Begin !!!
        l_entityTigger->transform->m_transform->Move(0.5f, 0.5f, 0.5f);

        //l_entityCube->transform->m_transform->Move(0.5f, 2.0f, 0.5f);
        //l_entityCube->transform->m_transform->Rotate(90.0f, 0.0f, 0.0f);

        l_entityCube->transform->m_transform->Move(0.0f, 0.0f, 0.0f);
        l_entityCube->transform->m_transform->Rotate(45.0f, 45.0f, 0.0f);
        l_entityCube->transform->m_transform->Scaling(0.01f, 0.01f, 0.01f);
    }

    void Game::Begin()
    {
        Debug::s_inst->ScreenLog("Game Begin");        //Debug
        m_engine->Begin();
    }


    void Game::Update()
    {
        m_engine->Update();
        UpdateInputs();
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
            Debug::s_inst->ScreenLog("Forward", l_fDebugDuration);
            _fForwardValue = 1;
        }
        else if (GetKeyState('S') & 0x8000)
        {
            Debug::s_inst->ScreenLog("Backward", l_fDebugDuration);
            _fForwardValue = -1;
        }
        else
        {
            _fForwardValue = 0;
        }

        //Horizontal inputs
        if (GetKeyState('D') & 0x8000)
        {
            Debug::s_inst->ScreenLog("Right", l_fDebugDuration);
            _fHorizontalValue = 1;
        }
        else if (GetKeyState('Q') & 0x8000)
        {
            Debug::s_inst->ScreenLog("Left", l_fDebugDuration);
            _fHorizontalValue = -1;
        }
        else
        {
            _fHorizontalValue = 0;
        }
    }

    void Game::UpdateCameraPosition()
    {
        
    }

#pragma endregion