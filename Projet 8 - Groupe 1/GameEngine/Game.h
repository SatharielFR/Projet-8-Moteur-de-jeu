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
			Engine* m_engine = nullptr;
			bool m_bIsRunning = false;
			bool m_bCursorIsLocked = false;
			RailManager* m_railManager = nullptr;
			Cart* m_cart = nullptr;
			TargetSpawner* m_targetSpawner = nullptr;
			Player* m_player = nullptr;
			SplashHud* m_splashHud = nullptr;
			MenuHud* m_menuHud = nullptr;
			GameHud* m_gameHud = nullptr;
		#pragma endregion

		#pragma region GamePointers
			Entity* m_entityCamera;
			CameraComponent* m_cameraComponent;
			Scene* m_sceneGame;
		#pragma endregion

		#pragma region PublicFunctions
			Game();
			void Init(HWND hWnd);
			void Begin();
			void Update();
			void Close();
		#pragma endregion

	private:
		#pragma region PrivateFunctions
			float _fForwardValue = 0;
			float _fHorizontalValue = 0;
			float _fSpeed = 8.f;// 0.05f;
			int _nbMouseX = 0;
			int _nbMouseY = 0;
			int _MouseMovementX;
			int _MouseMovementY;
			float _fCameraOffset = 3.f;
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