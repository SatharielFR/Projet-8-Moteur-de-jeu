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
			//Programme
			LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
			static LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
			static float gravity;

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
			HWND getHwnd() { return _hWnd; }
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
