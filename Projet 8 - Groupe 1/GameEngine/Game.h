#pragma once

#include "resource.h"
#include "framework.h"






#pragma region ForwardDeclaration

	class Entity;
	class CameraComponent;
	class RailManager;
	class Cart;
	class Player;
	class GameHud;
	class MenuHud;
	class SplashHud;
	class TargetSpawner;
#pragma endregion

//Our main game class
class Game 
{
	public:
		#pragma region publicVariables
			Engine* m_engine ;
			bool m_bIsRunning ;
			bool m_bCursorIsLocked ;
			RailManager* m_railManager;
			Cart* m_cart;
			TargetSpawner* m_targetSpawner;
			Player* m_player;
			SplashHud* m_splashHud ;
			MenuHud* m_menuHud;
			GameHud* m_gameHud;
		#pragma endregion

		#pragma region GamePointers
			Entity* m_entityCamera;
			CameraComponent* m_cameraComponent;
			Scene* m_sceneGame;
		#pragma endregion

		#pragma region PublicFunctions
			Game();
			~Game();
			void Init(HWND hWnd);
			void Begin();
			void StartGame();
			void Update();
			void Close();
		#pragma endregion

	private:
		#pragma region PrivateFunctions
			float _fForwardValue ;
			float _fHorizontalValue ;
			float _fSpeed;// 0.05f;
			int _nbMouseX;
			int _nbMouseY;
			int _MouseMovementX;
			int _MouseMovementY;
			float _fCameraOffset;
		#pragma endregion

		#pragma region PrivateFunctions	
			void InitLevel();
			void InitEntity();
			void InitCamera();
			void InitHUD();
			void UpdateInputs();
			void UpdateMouseInputs();
			void UpdateCameraTransfrom();
			void UpdateCollision();
		#pragma endregion
};