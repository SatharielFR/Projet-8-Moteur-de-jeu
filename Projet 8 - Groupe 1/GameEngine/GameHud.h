#pragma once
#include "framework.h"

class GameHud
{
	public:
		#pragma region PublicFunctions
			GameHud(Scene* scene);
			~GameHud();
			void Update();
		#pragma endregion


	private: 
		#pragma region RuntimeVariables
			Scene* _scene;
		#pragma endregion

		#pragma region Params
			D3DXCOLOR _colorTitle;
			D3DXCOLOR _colorContent;
		#pragma endregion

		#pragma region Content
			Text* _labelFpsTitle;
			Text* _labelFpsContent;
		#pragma endregion
};

