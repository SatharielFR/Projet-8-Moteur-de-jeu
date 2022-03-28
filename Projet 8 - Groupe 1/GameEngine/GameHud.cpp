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
    _colorFooter    = D3DXCOLOR(0, 0, 0, 0.5f);

    //Crosshair
    _spriteCrosshair = new Sprite();
    float l_fCrosshairScale = 60.0f;
    _spriteCrosshair->SetTexture("Crosshair.bmp");
    _spriteCrosshair->SetScale(l_fCrosshairScale);
    _spriteCrosshair->SetPosition((SCREEN_WIDTH / 2.0f)- (l_fCrosshairScale) -60,
                                  (SCREEN_HEIGHT/ 2.0f)- (l_fCrosshairScale));
    _spriteCrosshair->SetSpriteColor(&_colorTitle);
    l_gameHUD->AddSprite(_spriteCrosshair);

    //Footer
    int l_nbFooterHeight = 150;
    _spriteFooter = new Sprite();
    _spriteFooter->SetHeight(l_nbFooterHeight);
    _spriteFooter->SetWidth(SCREEN_WIDTH);
    _spriteFooter->SetPosition(0, 980 - l_nbFooterHeight);//SCREEN_HEIGHT - l_nbFooterHeight);
    _spriteFooter->SetSpriteColor(&_colorFooter);
    l_gameHUD->AddSprite(_spriteFooter);

    //Label FPS Title
    _labelFpsTitle = new Text();
    _labelFpsTitle->SetTextColor(_colorTitle);
    _labelFpsTitle->SetText("FPS : ");
    _labelFpsTitle->SetPosition(SCREEN_WIDTH-300, SCREEN_HEIGHT-80);
    l_gameHUD->AddText(_labelFpsTitle);

    //Label FPS Content
    _labelFpsContent = new Text();
    _labelFpsContent->SetTextColor(_colorContent);
    _labelFpsContent->SetPosition(SCREEN_WIDTH - 230, SCREEN_HEIGHT-80);
    l_gameHUD->AddText(_labelFpsContent);

    //Label Time Title
    _labelTimeTitle = new Text();
    _labelTimeTitle->SetTextColor(_colorTitle);
    _labelTimeTitle->SetText("Time : ");
    _labelTimeTitle->SetPosition(200, SCREEN_HEIGHT - 80);
    l_gameHUD->AddText(_labelTimeTitle);

    //Label Time Content
    _labelTimeContent = new Text();
    _labelTimeContent->SetTextColor(_colorContent);
    _labelTimeContent->SetPosition(300, SCREEN_HEIGHT - 80);
    l_gameHUD->AddText(_labelTimeContent);

    //Label Time Title
    _labelScoreTitle = new Text();
    _labelScoreTitle->SetTextColor(_colorTitle);
    _labelScoreTitle->SetText("Score : ");
    _labelScoreTitle->SetPosition(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 80);
    l_gameHUD->AddText(_labelScoreTitle);

    //Label Time Content
    _labelScoreContent = new Text();
    _labelScoreContent->SetTextColor(_colorContent);
    _labelScoreContent->SetPosition(SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT - 80);
    l_gameHUD->AddText(_labelScoreContent);
    _labelScoreContent->SetText("0");
}

GameHud::~GameHud()
{
}

void GameHud::Update()
{
    //FPS
    string l_strFpsContent = to_string(_engine->GetFps());
    _labelFpsContent->SetText(l_strFpsContent);
    //Time
    string l_strTimeContent = to_string((int)Timer::s_inst->GetSystemTimeEx());
    _labelTimeContent->SetText(l_strTimeContent);
}
