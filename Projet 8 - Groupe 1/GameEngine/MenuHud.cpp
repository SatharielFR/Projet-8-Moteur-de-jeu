
#include "MenuHud.h"
#include "GameHud.h"


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
	_colorBlack = D3DXCOLOR(0, 0, 0, 1.0f);

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
	_spriteTitle->SetTextureSize(1920, 1920);
	_spriteTitle->SetWidth(REAL_SCREEN_WIDTH);
	_spriteTitle->SetHeight(REAL_SCREEN_HEIGHT);
	_spriteTitle->SetPosition(0, 0);
	_spriteTitle->SetSpriteColor(&_colorContent);
	l_menuHUD->AddSprite(_spriteTitle);

	//Text Title
	//_labelTitle = new Text();
	//_labelTitle->SetFontSize(4);
	//_labelTitle->SetTextColor(_colorTitle);
	//_labelTitle->SetText("MineCart");
	//_labelTitle->SetPosition(SCREEN_WIDTH / 2 - 200, 100);
	//l_menuHUD->AddText(_labelTitle);

	//Button text
	//_labelPlay = new Text();
	//_labelPlay->SetFontSize(3);
	//_labelPlay->SetTextColor(_colorContent);
	//_labelPlay->SetText("Play");
	//_labelPlay->SetPosition(SCREEN_WIDTH / 2 - 60, 400);
	//l_menuHUD->AddText(_labelPlay);

	//_labelCredits = new Text();
	//_labelCredits->SetFontSize(3);
	//_labelCredits->SetTextColor(_colorContent);
	//_labelCredits->SetText("Credits");
	//_labelCredits->SetPosition(SCREEN_WIDTH / 2 - 115, 600);
	//l_menuHUD->AddText(_labelCredits);

	//_labelExit = new Text();
	//_labelExit->SetFontSize(3);
	//_labelExit->SetTextColor(_colorContent);
	//_labelExit->SetText("Exit");
	//_labelExit->SetPosition(SCREEN_WIDTH / 2 - 60, 800);
	//l_menuHUD->AddText(_labelExit);

	_labelGroupe = new Text();
	_labelGroupe->SetFontSize(1);
	_labelGroupe->SetTextColor(_colorBlack);
	_labelGroupe->SetText("Groupe 1 : Leo / Rodrigue / Janaky");
	_labelGroupe->SetPosition(SCREEN_WIDTH / 2 - 220, REAL_SCREEN_HEIGHT - 100 );
	l_menuHUD->AddText(_labelGroupe);

	//Buttons
	float l_nbButtonScale = 1.5;
	int l_nbSizePlayX = 1024 / 6 * l_nbButtonScale;
	int l_nbSizePlayY = 342	 / 8 * l_nbButtonScale;
	_buttonPlay = new Button(_engine);
	_buttonPlay->SetTexture("ButtonPlay-Default.bmp", "ButtonPlay-Hover.bmp");
	_buttonPlay->SetTextureResolution(1024, 342);
	_buttonPlay->SetWidth(l_nbSizePlayX);
	_buttonPlay->SetHeight(l_nbSizePlayY);
	_buttonPlay->SetPosition(REAL_SCREEN_WIDTH / 2 - l_nbSizePlayX, 400);
	_buttonPlay->SetDefaultColor(&_colorContent);
	_buttonPlay->SetHoverColor(&_colorContent);
	l_menuHUD->AddButton(_buttonPlay);
	_buttonPlay->m_OnClic = RUNNER(Play);	// Bind Function 

	int l_CreditsWidth = 1324 / 8 * 0.8 *l_nbButtonScale;
	int l_CreditsHeight = 342 / 6 * 0.8 *l_nbButtonScale;
	_buttonCredits = new Button(_engine);
	_buttonCredits->SetTexture("ButtonCredits-Default.bmp", "ButtonCredits-Hover.bmp");
	_buttonCredits->SetTextureResolution(1324, 342);
	_buttonCredits->SetWidth(l_CreditsWidth);
	_buttonCredits->SetHeight(l_CreditsHeight);
	_buttonCredits->SetPosition(REAL_SCREEN_WIDTH / 2 - l_CreditsWidth - 25, 505);
	_buttonCredits->SetDefaultColor(&_colorContent);
	_buttonCredits->SetHoverColor(&_colorContent);
	l_menuHUD->AddButton(_buttonCredits);
	_buttonCredits->m_OnClic = RUNNER(Credits);	// Bind Function 

	int l_nbSizeExitX = 1024 / 6 * l_nbButtonScale;
	int l_nbSizeExitY = 342	 / 8 * l_nbButtonScale;
	_buttonExit= new Button(_engine);
	_buttonExit->SetTexture("ButtonExit-Default.bmp", "ButtonExit-Hover.bmp");
	_buttonExit->SetTextureResolution(1024, 342);
	_buttonExit->SetWidth(l_nbSizeExitX);
	_buttonExit->SetHeight(l_nbSizeExitY);
	_buttonExit->SetPosition(REAL_SCREEN_WIDTH / 2 - l_nbSizeExitX, 630);
	_buttonExit->SetDefaultColor(&_colorContent);
	_buttonExit->SetHoverColor(&_colorContent);
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
