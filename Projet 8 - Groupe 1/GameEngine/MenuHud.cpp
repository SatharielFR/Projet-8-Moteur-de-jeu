
#include "MenuHud.h"

#include "GameHud.h"

MenuHud::MenuHud(Scene* scene, Engine* engine)
{
	_scene = scene;
	_engine = engine;

	HUD* l_menuHUD = new HUD();
	_scene->AddHUD(l_menuHUD);

	//Colors
	_colorTitle =		D3DXCOLOR(1, 0.835, 0.101, 1);
	_colorContent =		D3DXCOLOR(1,   1, 1, 1);
	_colorBackground =	D3DXCOLOR(0.094, 0.309, 0.364, 1);

	//Background
	_spriteBackground = new Sprite();
	_spriteBackground->SetTexture("Default.bmp");
	_spriteBackground->SetWidth(SCREEN_WIDTH);
	_spriteBackground->SetHeight(SCREEN_HEIGHT);
	_spriteBackground->SetPosition(0,0);
	_spriteBackground->SetSpriteColor(&_colorBackground);
	l_menuHUD->AddSprite(_spriteBackground);


	//Title
	_labelTitle = new Text();
	_labelTitle->SetFontSize(4);
	_labelTitle->SetTextColor(_colorTitle);
	_labelTitle->SetText("MineCart");
	_labelTitle->SetPosition(SCREEN_WIDTH/2 - 200, 100);
	l_menuHUD->AddText(_labelTitle);

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
	_buttonPlay = new Button();
	//_buttonPlay->SetTexture("Default.bmp");
	//_buttonPlay->SetWidth(SCREEN_WIDTH);
	//_buttonPlay->SetHeight(SCREEN_HEIGHT);
	//_buttonPlay->SetPosition(0, 0);
	//_buttonPlay->SetSpriteColor(&_colorBackground);
	l_menuHUD->AddButton(_buttonPlay);
}

MenuHud::~MenuHud()
{
}

void MenuHud::Update()
{
}
