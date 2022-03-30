#pragma once
#include "framework.h"

#pragma region ForwardDeclaration
	class Game;
	class Player;
#pragma endregion

class GameHud
{
	public:
		#pragma region PublicFunctions
			GameHud(Scene* scene, Engine* engine, Game* game);
			~GameHud();
			void Update();
			void ShowEndMenu();
			void ShowGameHud();
		#pragma endregion


	private: 
		#pragma region UtilityFunctions
			void CreateMain();
			void DestroyMain();
			void CreateEnd();
			void DestroyEnd();
			void Return();
		#pragma endregion

		#pragma region RuntimeVariables
			Engine* _engine;
			Game* _game;
			Scene* _scene;
			HUD* _gameHUD;
			bool _bEndMenuIsActive = false;
			bool _bGameHudIsActive = false;
		#pragma endregion

		#pragma region Params
			D3DXCOLOR _colorTitle;
			D3DXCOLOR _colorContent;
			D3DXCOLOR _colorFooter;
			D3DXCOLOR _colorWhite;
		#pragma endregion

		#pragma region ContentMain
			//Sprites
			Sprite* _spriteCrosshair;
			Sprite* _spriteFooter;
			//FPS
			Text* _labelFpsTitle;
			Text* _labelFpsContent;
			//Time
			Text* _labelTimeTitle;
			Text* _labelTimeContent;
			//Score
			Text* _labelScoreTitle;
			Text* _labelScoreContent;
		#pragma endregion

		#pragma region ContentMain
			//Sprites
			Sprite* _spriteBackgroundEnd;
			//Time
			Text* _labelTimeEnd;
			//Score
			Text* _labelScoreEnd;
			//Button Return
			Button* _buttonReturn;
		#pragma endregion
};

