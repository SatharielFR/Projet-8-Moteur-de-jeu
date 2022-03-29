#pragma once
#include "framework.h"

class MenuHud
{
	public:
	#pragma region PublicFunctions
		MenuHud(Scene* scene, Engine* engine);
		~MenuHud();
		void Update();
	#pragma endregion


	private:
	#pragma region RuntimeVariables
		Engine* _engine;
		Scene* _scene;
	#pragma endregion

	#pragma region Params
		D3DXCOLOR _colorBackground;
		D3DXCOLOR _colorTitle;
		D3DXCOLOR _colorContent;
	#pragma endregion

	#pragma region Content
		//Background
		Sprite* _spriteBackground;
		//Title
		Text* _labelTitle;
		//Buttons text
		Text* _labelPlay;
		Text* _labelCredits;
		Text* _labelExit;
		//Buttons
		Button* _buttonPlay;
	#pragma endregion
};