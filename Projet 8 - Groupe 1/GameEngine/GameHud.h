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
		#pragma endregion

		#pragma region Content
			Sprite* _spriteCrosshair;
			Text* _labelFpsTitle;
			Text* _labelFpsContent;
		#pragma endregion
};

