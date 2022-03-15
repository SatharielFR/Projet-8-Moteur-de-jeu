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
        m_engine = new Engine(hWnd);
        //Create a map for the game
        Scene* sceneMain = new Scene("Main");
        m_engine->GetSceneMananger()->AddScene(sceneMain);
        m_engine->GetSceneMananger()->OpenScene("Main");
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
        //Forward inputs
        if (GetKeyState('Z') & 0x8000)
        {
            _fForwardValue = 1;
        }
        else if (GetKeyState('S') & 0x8000)
        {
            _fForwardValue = -1;
        }
        else
        {
            _fForwardValue = 0;
        }

        //Horizontal inputs
        if (GetKeyState('Q') & 0x8000)
        {
            _fHorizontalValue = 1;
        }
        else if (GetKeyState('D') & 0x8000)
        {
            _fHorizontalValue = -1;
        }
        else
        {
            _fHorizontalValue = 0;
        }
    }

    void Game::UpdateCameraPosition()
    {
        //vecCamPosition.x += _fHorizontalValue  * _fSpeed;
        //vecCamPosition.z += _fForwardValue     * _fSpeed;
    }

#pragma endregion