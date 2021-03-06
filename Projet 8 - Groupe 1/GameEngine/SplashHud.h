#pragma once
#include "framework.h"

class SplashHud
{
	public:
	#pragma region PublicFunctions
		SplashHud(Scene* scene, Engine* engine);
		~SplashHud();
		void Update();
	#pragma endregion


	private:
	#pragma region RuntimeVariables
		Engine* _engine;
		Scene* _scene;
	#pragma endregion

	#pragma region Params
		float _fSoundDelay = 2.5f;
		bool _bSoundHasBeenPlayed = false;
		float _fFadeSpeed;
		float _fFadeValue;
		float _fFadeDuration = 4.0f;
		D3DXCOLOR _colorBackground;
		D3DXCOLOR _colorSplash;
	#pragma endregion

	#pragma region Content
		//Background
		Sprite* _spriteBackground;
		Sprite* _spriteSplashBackground;
		Sprite* _spriteSplash;
	#pragma endregion

};

