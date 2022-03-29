#include "SplashHud.h"

SplashHud::SplashHud(Scene* scene, Engine* engine)
{
    _engine = engine;
    _scene = scene;

    HUD* l_SplashHud = new HUD();
    _scene->AddHUD(l_SplashHud);

	_fFadeSpeed = 0.0002f;

    //Colors
	_fFadeValue = 0;
    _colorBackground = D3DXCOLOR(0.1, 0.1, 0.1, 0);
    _colorSplash = D3DXCOLOR(1, 1, 1, 0);

	//Background
	_spriteBackground = new Sprite();
	_spriteBackground->SetTexture("Default.bmp");
	_spriteBackground->SetWidth(SCREEN_WIDTH);
	_spriteBackground->SetHeight(SCREEN_HEIGHT);
	_spriteBackground->SetPosition(0, 0);
	_spriteBackground->SetSpriteColor(&_colorBackground);
	l_SplashHud->AddSprite(_spriteBackground);

	//Splash
	_spriteSplash = new Sprite();
	_spriteSplash->SetTexture("Splash.bmp");
	_spriteSplash->SetWidth(900);
	_spriteSplash->SetHeight(900);
	_spriteSplash->SetPosition(270, 50);
	_spriteSplash->SetSpriteColor(&_colorSplash);
	l_SplashHud->AddSprite(_spriteSplash);
}

SplashHud::~SplashHud()
{
}

void SplashHud::Update()
{
	if (_fFadeValue < 1.0f)
	{
		_fFadeValue = (Timer::s_inst->GetSystemTimeEx()  / _fFadeDuration);
	}
	else if (_fFadeValue >= 1.0f)
	{
		ShowCursor(true);
		_engine->GetSceneMananger()->OpenScene("Menu");
		_engine->GetSceneMananger()->CloseScene("Splash");
	}

	if (!_bSoundHasBeenPlayed && Timer::s_inst->GetSystemTimeEx() > _fSoundDelay)
	{
		//Sound
		PlaySound(TEXT("..\\Ressources\\TigerRoar.wav"), NULL, SND_FILENAME | SND_ASYNC);
		_bSoundHasBeenPlayed = true;
	}

	_colorSplash = D3DXCOLOR(1, 1, 1, _fFadeValue);
	_spriteSplash->SetSpriteColor(&_colorSplash);
}
