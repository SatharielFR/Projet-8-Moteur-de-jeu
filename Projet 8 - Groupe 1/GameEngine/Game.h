#pragma once

#include "resource.h"
#include "framework.h"
// Fichiers d'en-tête C RunTime
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// Déclarations anticipées des fonctions incluses dans ce module de code :
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
//{
//    #ifndef NDEBUG    // In debug mode allocate console and enable memory debugging
//        AllocConsole();    
//        freopen("conout$", "w", stdout);    
//        freopen("conout$", "w", stderr);    
//        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
//    #endif 
//
//    #ifdef NDEBUG    // Only catch exceptions in release mode. In debug mode the IDE    
//                    // will catch them and jump to the source.    
//        try
//    #endif    
//        {   
//            // Put your main code here    
//        }
//    #ifdef NDEBUG    
//        catch 
//            (std::exception& e)    
//        {       
//            // Display error box or something    
//        }
//    #endif
//    #ifndef 
//        NDEBUG    FreeConsole();
//    #endif    
//
//    return 0;
//}

// function prototypes
void initD3D(HWND hWnd);    // sets up and initializes Direct3D
void render_frame(void);    // renders a single frame
void cleanD3D(void);    // closes Direct3D and releases memory
void init_graphics(void);    // 3D declarations
//Fonctions Custom
void Update();
void UpdateInputs();
void UpdateCameraPosition();