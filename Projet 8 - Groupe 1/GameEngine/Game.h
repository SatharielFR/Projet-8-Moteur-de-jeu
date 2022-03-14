#pragma once

#include "resource.h"
#include "framework.h"
#include "../Engine/Engine.h"


// Déclarations anticipées des fonctions incluses dans ce module de code :
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


// function prototypes
//void initD3D(HWND hWnd);    // sets up and initializes Direct3D
//void render_frame(void);    // renders a single frame
//void cleanD3D(void);    // closes Direct3D and releases memory
//void init_graphics(void);    // 3D declarations


class Game* g_game;

//Our main game class
class Game 
{
	public:
		Game();
		Engine* m_engine = nullptr;

	private:
		//Fonctions Custom
		void Update();
		void UpdateInputs();
		void UpdateCameraPosition();
};