#include "Game.h"



// Déclarations anticipées des fonctions incluses dans ce module de code :
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
#pragma region GlobalVariables
HINSTANCE hInst;                                // instance actuelle
WCHAR szTitle[MAX_LOADSTRING];                  // Texte de la barre de titre
WCHAR szWindowClass[MAX_LOADSTRING];            // nom de la classe de fenêtre principale
#pragma endregion

#pragma region WindowsEntry
    // the entry point for any Windows program
    int WINAPI WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
    {
        #ifdef _DEBUG
            _CrtMemState memStateInit;
            _CrtMemCheckpoint(&memStateInit);
        #endif
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
            WS_POPUP, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
            NULL, NULL, hInstance, NULL);
        ShowWindow(hWnd, nCmdShow);

        // Set up and initialize Direct3D
        Game* game = new Game;
        game->Init(hWnd);
        game->Begin();

        // Enter the main loop:
        MSG msg;
        game->m_bIsRunning = true;
        while (game->m_bIsRunning == true)
        {
            game->Update();

            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                if (msg.message == WM_QUIT)
                {
                    game->m_bIsRunning = false;
                    break;
                }
            }

        }
        game->Close();
        delete game;

        #ifdef _DEBUG
            _CrtMemState memStateEnd, memStateDiff;
            _CrtMemCheckpoint(&memStateEnd);
            if (_CrtMemDifference(&memStateDiff, &memStateInit, &memStateEnd))
            {
                MessageBoxA(NULL, "MEMORY LEAKS", "DISCLAIMER", 0);
            }
        #endif 
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