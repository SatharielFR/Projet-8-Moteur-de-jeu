#include "GameHud.h"

GameHud::GameHud(Scene* scene, Engine* engine)
{
    _engine = engine;
    _scene = scene;

    HUD* l_gameHUD = new HUD();
    _scene->AddHUD(l_gameHUD);

    //Colors
    _colorTitle     = D3DXCOLOR(255,255,255,255);
    _colorContent   = D3DXCOLOR(255, 0, 242,255);

    //Crosshair
    _spriteCrosshair = new Sprite();
    int l_nbCrosshairTextSize = 1024;
    float l_fCrosshairScale = 0.06f;
    _spriteCrosshair->SetTexture("Crosshair.bmp");
    _spriteCrosshair->SetHeight(l_nbCrosshairTextSize);
    _spriteCrosshair->SetWidth(l_nbCrosshairTextSize);
    _spriteCrosshair->SetScale(l_fCrosshairScale);
    _spriteCrosshair->SetPosition((SCREEN_WIDTH / 2) - (l_nbCrosshairTextSize*l_fCrosshairScale)/2 ,
                                  (SCREEN_HEIGHT/ 2) - (l_nbCrosshairTextSize*l_fCrosshairScale)/2 );
    _spriteCrosshair->SetSpriteColor(&_colorTitle);
    l_gameHUD->AddSprite(_spriteCrosshair);

    //Label FPS Title
    _labelFpsTitle = new Text();
    _labelFpsTitle->SetTextColor(_colorTitle);
    _labelFpsTitle->SetText("FPS : ");
    _labelFpsTitle->SetPosition(SCREEN_WIDTH-300, 20);
    l_gameHUD->AddText(_labelFpsTitle);

    //Label FPS Content
    _labelFpsContent = new Text();
    _labelFpsContent->SetTextColor(_colorContent);
    _labelFpsContent->SetPosition(SCREEN_WIDTH - 230, 20);
    l_gameHUD->AddText(_labelFpsContent);
}

GameHud::~GameHud()
{
}

void GameHud::Update()
{
    string l_strFpsContent = to_string(_engine->GetFps());
    _labelFpsContent->SetText(l_strFpsContent);
}
