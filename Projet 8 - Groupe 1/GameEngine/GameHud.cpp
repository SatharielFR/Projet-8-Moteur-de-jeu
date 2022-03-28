#include "GameHud.h"

GameHud::GameHud(Scene* scene, Engine* engine)
{
    _engine = engine;
    _scene = scene;

    HUD* l_gameHUD = new HUD();
    _scene->AddHUD(l_gameHUD);

    //Colors
    _colorTitle     = D3DXCOLOR(255,255,255,255);
    _colorContent   = D3DXCOLOR(0,0,255,255);

    //Label FPS Title
    _labelFpsTitle = new Text();
    _labelFpsTitle->SetTextColor(_colorTitle);
    _labelFpsTitle->SetText("FPS : ");
    _labelFpsTitle->SetPosition(200, 20);
    l_gameHUD->AddText(_labelFpsTitle);

    //Label FPS Content
    _labelFpsContent = new Text();
    _labelFpsContent->SetTextColor(_colorContent);
    _labelFpsContent->SetPosition(300, 20);
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
