#include "GameHud.h"
#include "Game.h"
#include "Player.h"

GameHud::GameHud(Scene* scene, Engine* engine, Game* game)
{
    _engine = engine;
    _scene = scene;
    _game = game;

    _gameHUD = new HUD();
    _scene->AddHUD(_gameHUD);

    //Colors
    _colorTitle     = D3DXCOLOR(255,255,255,255);
    _colorContent   = D3DXCOLOR(255, 237, 0,255);
    _colorFooter    = D3DXCOLOR(0, 0, 0, 0.65f);
    _colorWhite     = D3DXCOLOR(1, 1, 1, 1);
}

GameHud::~GameHud()
{
}

void GameHud::Update()
{
    //FPS
    if (_labelFpsContent)
    {
        string l_strFpsContent = to_string(_engine->GetFps());
        _labelFpsContent->SetText(l_strFpsContent);
    }

    //Time
    if (_labelTimeContent)
    {
        string l_strTimeContent = to_string((int)Timer::s_inst->GetSystemTimeEx() - _nbTimeGameStart);
        _labelTimeContent->SetText(l_strTimeContent);
    }

    //Score
    if (_labelScoreContent)
    {
        string l_strScoreContent = to_string((int)_game->m_player->score);
        _labelScoreContent->SetText(l_strScoreContent);
    }
}

void GameHud::ShowEndMenu()
{
    if (!_bEndMenuIsActive)
    {
        DestroyMain();
        CreateEnd();
    }
}

void GameHud::ShowGameHud()
{
    if (!_bGameHudIsActive)
    {
        DestroyEnd();
        CreateMain();
    }
}

void GameHud::CreateMain()
{
    //Crosshair
    _spriteCrosshair = new Sprite();
    float l_fCrosshairScale = 60.0f;
    _spriteCrosshair->SetTexture("Crosshair.bmp");
    _spriteCrosshair->SetScale(l_fCrosshairScale);
    _spriteCrosshair->SetPosition((SCREEN_WIDTH / 2.0f) - (l_fCrosshairScale)-60,
        (SCREEN_HEIGHT / 2.0f) - (l_fCrosshairScale));
    _spriteCrosshair->SetSpriteColor(&_colorTitle);
    _gameHUD->AddSprite(_spriteCrosshair);

    //Footer
    int l_nbFooterHeight = 150;
    _spriteFooter = new Sprite();
    _spriteFooter->SetHeight(l_nbFooterHeight);
    _spriteFooter->SetWidth(SCREEN_WIDTH);
    _spriteFooter->SetPosition(0, 980 - l_nbFooterHeight);//SCREEN_HEIGHT - l_nbFooterHeight);
    _spriteFooter->SetSpriteColor(&_colorFooter);
    _gameHUD->AddSprite(_spriteFooter);

    //Label FPS Title
    _labelFpsTitle = new Text();
    _labelFpsTitle->SetTextColor(_colorTitle);
    _labelFpsTitle->SetText("FPS : ");
    _labelFpsTitle->SetPosition(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 80);
    _gameHUD->AddText(_labelFpsTitle);

    //Label FPS Content
    _labelFpsContent = new Text();
    _labelFpsContent->SetTextColor(_colorContent);
    _labelFpsContent->SetPosition(SCREEN_WIDTH - 230, SCREEN_HEIGHT - 80);
    _gameHUD->AddText(_labelFpsContent);

    //Label Time Title
    _labelTimeTitle = new Text();
    _labelTimeTitle->SetTextColor(_colorTitle);
    _labelTimeTitle->SetText("Time : ");
    _labelTimeTitle->SetPosition(200, SCREEN_HEIGHT - 80);
    _gameHUD->AddText(_labelTimeTitle);

    //Label Time Content
    _labelTimeContent = new Text();
    _labelTimeContent->SetTextColor(_colorContent);
    _labelTimeContent->SetPosition(300, SCREEN_HEIGHT - 80);
    _gameHUD->AddText(_labelTimeContent);

    //Label Time Title
    _labelScoreTitle = new Text();
    _labelScoreTitle->SetTextColor(_colorTitle);
    _labelScoreTitle->SetText("Score : ");
    _labelScoreTitle->SetPosition(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 80);
    _gameHUD->AddText(_labelScoreTitle);

    //Label Time Content
    _labelScoreContent = new Text();
    _labelScoreContent->SetTextColor(_colorContent);
    _labelScoreContent->SetPosition(SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT - 80);
    _gameHUD->AddText(_labelScoreContent);
    _labelScoreContent->SetText("0");

    _nbTimeGameStart = (int)Timer::s_inst->GetSystemTimeEx();
    ShowCursor(false);
    _bGameHudIsActive = true;
}

void GameHud::DestroyMain()
{
    if (_bGameHudIsActive)
    {
        //Crosshair
        _gameHUD->RemoveSprite(_spriteCrosshair);

        //Footer
        _gameHUD->RemoveSprite(_spriteFooter);

        //Label FPS Title
        _gameHUD->RemoveText(_labelFpsTitle);

        //Label FPS Content
        _gameHUD->RemoveText(_labelFpsContent);

        //Label Time Title
        _gameHUD->RemoveText(_labelTimeTitle);

        //Label Time Content
        _gameHUD->RemoveText(_labelTimeContent);

        //Label Time Title
        _gameHUD->RemoveText(_labelScoreTitle);

        //Label Time Content
        _gameHUD->RemoveText(_labelScoreContent);

        _bGameHudIsActive = false;
    }
}

void GameHud::CreateEnd()
{
    //Background
    _spriteBackgroundEnd = new Sprite();
    _spriteBackgroundEnd->SetTexture("BackgroundEnd.bmp");
    _spriteBackgroundEnd->SetTextureSize(1920, 1920);
    _spriteBackgroundEnd->SetWidth(REAL_SCREEN_WIDTH);
    _spriteBackgroundEnd->SetHeight(REAL_SCREEN_HEIGHT);
    _spriteBackgroundEnd->SetPosition(0, 0);
    _spriteBackgroundEnd->SetSpriteColor(new D3DXCOLOR(1, 1, 1, 1));
    _gameHUD->AddSprite(_spriteBackgroundEnd);

    //Time
    _labelTimeEnd = new Text();
    _labelTimeEnd->SetTextColor(_colorContent);
    _labelTimeEnd->SetFontSize(2.5);
    _labelTimeEnd->SetPosition(SCREEN_WIDTH/2 - 200, SCREEN_HEIGHT/2 - 55);
    string l_strTimeContent = to_string((int)Timer::s_inst->GetSystemTimeEx() - _nbTimeGameStart) + "s";
    _labelTimeEnd->SetText(l_strTimeContent);
    _gameHUD->AddText(_labelTimeEnd);

    //Score
    _labelScoreEnd = new Text();
    _labelScoreEnd->SetTextColor(_colorContent);
    _labelScoreEnd->SetFontSize(2.5);
    _labelScoreEnd->SetPosition(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 55);
    string l_strScoreContent = to_string((int)_game->m_player->score);
    _labelScoreEnd->SetText(l_strScoreContent);
    _gameHUD->AddText(_labelScoreEnd);

    //Button Return
    float l_nbButtonScale = 1.5;
    int l_nbSizeExitX = 1024 / 6 * l_nbButtonScale;
    int l_nbSizeExitY = 342 / 8 * l_nbButtonScale;
    _buttonReturn = new Button(_engine);
    _buttonReturn->SetTexture("ButtonExit-Default.bmp", "ButtonExit-Hover.bmp");
    _buttonReturn->SetTextureResolution(1024, 342);
    _buttonReturn->SetWidth(l_nbSizeExitX);
    _buttonReturn->SetHeight(l_nbSizeExitY);
    _buttonReturn->SetPosition(REAL_SCREEN_WIDTH / 2 - l_nbSizeExitX, 630);
    _buttonReturn->SetDefaultColor(&_colorWhite);
    _buttonReturn->SetHoverColor(&_colorWhite);
    _gameHUD->AddButton(_buttonReturn);
    _buttonReturn->m_OnClic = RUNNER(Return);	// Bind Function 

    ShowCursor(true);
    _bEndMenuIsActive = true;
}

void GameHud::DestroyEnd()
{
    if (_bEndMenuIsActive)
    {
        //Background
        _gameHUD->RemoveSprite(_spriteBackgroundEnd);

        //Time
        _gameHUD->RemoveText(_labelTimeEnd);

        //Score
        _gameHUD->RemoveText(_labelScoreEnd);

        //Button Return
        _gameHUD->RemoveButton(_buttonReturn);

        _bEndMenuIsActive = false;
    }
}

void GameHud::Return()
{
    _engine->GetSceneMananger()->OpenScene("Menu");
    ShowCursor(true);
}
