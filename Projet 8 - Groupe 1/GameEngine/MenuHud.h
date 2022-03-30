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
		D3DXCOLOR _colorButtonDefault;
		D3DXCOLOR _colorButtonHover;
		D3DXCOLOR _colorBlack;
	#pragma endregion

	#pragma region Content
		//Background
		Sprite* _spriteBackground;
		Sprite* _spriteTitle;
		//Title
		Text* _labelTitle;
		//Buttons text
		Text* _labelPlay;
		Text* _labelCredits;
		Text* _labelExit;
		Text* _labelGroupe;
		//Buttons
		Button* _buttonPlay;
		Button* _buttonCredits;
		Button* _buttonExit;
	#pragma endregion

	#pragma region OnClic
		void Play();
		void Credits();
		void Exit();
	#pragma endregion
};