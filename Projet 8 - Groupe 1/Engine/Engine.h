#pragma once

#pragma region ForwardDeclaration
	class SceneManager;
	class Component;
	class Debug;
	class Timer;
#pragma endregion

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
			void Begin();
			void Update();
			void Close();
		#pragma endregion 

		#pragma region Accessors
			SceneManager* GetSceneMananger() { return _sceneManager; }
		#pragma endregion

	private:
		#pragma region PrivateVariables
			HWND _hWnd;
			SceneManager * _sceneManager = nullptr;
			Debug* _debug = nullptr;
			Timer* _timer = nullptr;
			D3DCOLOR _ClearColor = D3DCOLOR_XRGB(49, 51, 54);
		#pragma endregion 

		#pragma region PrivateFunctions
			void Init();
			D3DMATERIAL9 CreateTestMaterial();

		#pragma endregion 

		#pragma region 3D Display
			void InitD3D(HWND hWnd);   // sets up and initializes Direct3D
			void InitGraphics(void);    // 3D declarations
			void RenderFrame(void);		// renders a single frame
			void CleanD3D(void);		// closes Direct3D and releases memory
		#pragma endregion
};
