#pragma once
#include "framework.h"

class GameHud
{
	public:
		#pragma region PublicFunctions
			GameHud(Scene* scene, Engine* engine);
			~GameHud();
			void Update();
		#pragma endregion


	private: 
		#pragma region RuntimeVariables
			Engine* _engine;
			Scene* _scene;
		#pragma endregion

		#pragma region Params
			D3DXCOLOR _colorTitle;
			D3DXCOLOR _colorContent;
			D3DXCOLOR _colorFooter;
		#pragma endregion

		#pragma region Content
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
};

