
#include "MenuHud.h"
#include "GameHud.h"

#define RUNNER(str)[=]{str();}


MenuHud::MenuHud(Scene* scene, Engine* engine)
{
	_scene = scene;
	_engine = engine;

	HUD* l_menuHUD = new HUD();
	_scene->AddHUD(l_menuHUD);

	//Colors
	_colorTitle = D3DXCOLOR(1, 0.835, 0.101, 1);
	_colorContent = D3DXCOLOR(1, 1, 1, 1);
	_colorBackground = D3DXCOLOR(1, 1, 1, 1);
	_colorButtonDefault = D3DXCOLOR(0, 0, 0, 0.2f);
	_colorButtonHover = _colorTitle;

	//Background
	_spriteBackground = new Sprite();
	_spriteBackground->SetTexture("Default.bmp");
	_spriteBackground->SetWidth(SCREEN_WIDTH);
	_spriteBackground->SetHeight(SCREEN_HEIGHT);
	_spriteBackground->SetPosition(0, 0);
	_spriteBackground->SetSpriteColor(&_colorBackground);
	l_menuHUD->AddSprite(_spriteBackground);

	//Sprite Title
	_spriteTitle = new Sprite();
	_spriteTitle->SetTexture("MenuBackground.bmp");
	_spriteTitle->SetTextureSize(1920);
	_spriteTitle->SetWidth(SCREEN_WIDTH);
	_spriteTitle->SetHeight(SCREEN_HEIGHT);
	_spriteTitle->SetPosition(0, 0);
	_spriteTitle->SetSpriteColor(&_colorContent);
	l_menuHUD->AddSprite(_spriteTitle);

	//Title
	//_labelTitle = new Text();
	//_labelTitle->SetFontSize(4);
	//_labelTitle->SetTextColor(_colorTitle);
	//_labelTitle->SetText("MineCart");
	//_labelTitle->SetPosition(SCREEN_WIDTH / 2 - 200, 100);
	//l_menuHUD->AddText(_labelTitle);

	//Button text
	_labelPlay = new Text();
	_labelPlay->SetFontSize(3);
	_labelPlay->SetTextColor(_colorContent);
	_labelPlay->SetText("Play");
	_labelPlay->SetPosition(SCREEN_WIDTH / 2 - 60, 400);
	l_menuHUD->AddText(_labelPlay);

	_labelCredits = new Text();
	_labelCredits->SetFontSize(3);
	_labelCredits->SetTextColor(_colorContent);
	_labelCredits->SetText("Credits");
	_labelCredits->SetPosition(SCREEN_WIDTH / 2 - 115, 600);
	l_menuHUD->AddText(_labelCredits);

	_labelExit = new Text();
	_labelExit->SetFontSize(3);
	_labelExit->SetTextColor(_colorContent);
	_labelExit->SetText("Exit");
	_labelExit->SetPosition(SCREEN_WIDTH / 2 - 60, 800);
	l_menuHUD->AddText(_labelExit);

	//Button
	float l_fButtonWidth = 400;
	float l_fButtonHeight = 100;

	_buttonPlay = new Button(_engine);
	//_buttonPlay->SetTexture("Default.bmp");
	_buttonPlay->SetWidth(l_fButtonWidth);
	_buttonPlay->SetHeight(l_fButtonHeight);
	_buttonPlay->SetPosition(SCREEN_WIDTH / 2 - l_fButtonWidth, 350);
	_buttonPlay->SetDefaultColor(&_colorButtonDefault);
	_buttonPlay->SetHoverColor(&_colorButtonHover);
	l_menuHUD->AddButton(_buttonPlay);
	_buttonPlay->m_OnClic = RUNNER(Play);	// Bind Function 


	_buttonCredits = new Button(_engine);
	//_buttonPlay->SetTexture("Default.bmp");
	_buttonCredits->SetWidth(l_fButtonWidth);
	_buttonCredits->SetHeight(l_fButtonHeight);
	_buttonCredits->SetPosition(SCREEN_WIDTH / 2 - l_fButtonWidth, 540);
	_buttonCredits->SetDefaultColor(&_colorButtonDefault);
	_buttonCredits->SetHoverColor(&_colorButtonHover);
	l_menuHUD->AddButton(_buttonCredits);
	_buttonCredits->m_OnClic = RUNNER(Credits);	// Bind Function 

	_buttonExit= new Button(_engine);
	//_buttonPlay->SetTexture("Default.bmp");
	_buttonExit->SetWidth(l_fButtonWidth);
	_buttonExit->SetHeight(l_fButtonHeight);
	_buttonExit->SetPosition(SCREEN_WIDTH / 2 - l_fButtonWidth, 720);
	_buttonExit->SetDefaultColor(&_colorButtonDefault);
	_buttonExit->SetHoverColor(&_colorButtonHover);
	l_menuHUD->AddButton(_buttonExit);
	_buttonExit->m_OnClic = RUNNER(Exit);	// Bind Function 
}

MenuHud::~MenuHud()
{
}

void MenuHud::Update()
{
}

void MenuHud::Play()
{	
	Debug::s_inst->ScreenLog("Play");
	_engine->GetSceneMananger()->OpenScene("Game");
	_engine->GetSceneMananger()->CloseScene("Menu");
	ShowCursor(false);
}

void MenuHud::Credits()
{
}

void MenuHud::Exit()
{
	PostQuitMessage(WM_CLOSE);
}
