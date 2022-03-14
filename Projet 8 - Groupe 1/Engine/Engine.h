#pragma once

//#include "SceneManager.h"
//#include "Moteur.h"
//#include "framework.h"

class SceneManager;

class Engine
{
	public:
		#pragma region PublicVariables
			//#define SCREEN_WIDTH  800 
			//#define SCREEN_HEIGHT 800
			//#define MAX_LOADSTRING 100
			//Programme
			LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
			LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
			LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;    // the pointer to the vertex buffer
			LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;     // the pointer to the index buffer
			//Matrices 
			D3DXMATRIX matView;    // the view transform matrix
			D3DXVECTOR3 vecCamPosition = D3DXVECTOR3(0.0f, 0.0f, 15.0f);   // the camera position
			D3DXVECTOR3 vecLookAtPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);    // the look-at position
			D3DXVECTOR3 vecUpDirection = D3DXVECTOR3(0.0f, 1.0f, 0.0f);    // the up direction
			//Font variable
			ID3DXFont* Font = 0;
		#pragma endregion 

		#pragma region PublicFunctions
			Engine(HWND hWnd);
			void Update();
			void Close();
		#pragma endregion 

		#pragma region Accessors
			SceneManager* GetSceneMananger() { return _sceneManager; }
		#pragma endregion

	private:
		#pragma region PrivateVariables
			HWND _hWnd;
			SceneManager * _sceneManager;
		#pragma endregion 

		#pragma region PrivateFunctions
			void Init();
		#pragma endregion 

		#pragma region 3D Display
			void InitD3D(HWND hWnd);   // sets up and initializes Direct3D
			void InitGraphics(void);    // 3D declarations
			void RenderFrame(void);		// renders a single frame
			void CleanD3D(void);		// closes Direct3D and releases memory
		#pragma endregion
};
