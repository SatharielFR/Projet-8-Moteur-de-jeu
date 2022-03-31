#pragma once

#pragma region ForwardDeclaration
	class SceneManager;
	class RigidbodyComponent;
	class Component;
	class Debug;
	class Timer;
	class HUD;
	class Entity;
	class Scene;
#pragma endregion

struct CollisionResult {
	public:
		bool result;
		RigidbodyComponent* rigidbody1;
		RigidbodyComponent* rigidbody2;

		CollisionResult(bool r, RigidbodyComponent* rigidbd1, RigidbodyComponent* rigidbd2) {
			result = r;
			rigidbody1 = rigidbd1;
			rigidbody2 = rigidbd2;
		}
};

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
			~Engine();
			void Begin();
			void Update();
			void Close();
			int GetFps() {return _nbFps;}
			void CollisionCheck();
			void Collision(RigidbodyComponent* rb1, RigidbodyComponent* rb2);
			vector<CollisionResult*> GetListResult() { return collisionResult; }
			void RemoveCollisionResult(CollisionResult* CollsionToRem);
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
			HUD* _HudToDraw = nullptr;
			vector<CollisionResult*> collisionResult;
			int _nbFps;
			int _nbFpsCount;
			float _fLastCheckFpsTime;
			D3DCOLOR ClearColor;
			vector<Entity*> l_entities;
			Scene* _sceneCurrent;
			Scene* _scenePrevious;
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
