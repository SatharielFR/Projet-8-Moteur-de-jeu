#pragma once

#include "resource.h"
#include "framework.h"


// D�clarations anticip�es des fonctions incluses dans ce module de code�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


#pragma region ForwardDeclaration
	class Game* g_game;
	class Entity;
	class CameraComponent;
#pragma endregion

//Our main game class
class Game 
{
	public:
		#pragma region publicVariables
			Engine* m_engine = nullptr;
			bool m_bIsRunning = false;
		#pragma endregion

		#pragma region GamePointers
			Entity* m_entityCamera;
			CameraComponent* m_cameraComponent;
		#pragma endregion

		#pragma region PublicFunctions
			Game(HWND hWnd);
			void Begin();
			void Update();
			void Close();
		#pragma endregion

	private:
		#pragma region PrivateFunctions
			float _fForwardValue = 0;
			float _fHorizontalValue = 0;
			float _fSpeed = 0.5f;
		#pragma endregion

		#pragma region PrivateFunctions	
			void UpdateInputs();
			void UpdateCameraPosition();
		#pragma endregion
};