#include "pch.h"
#include "Framework.h"

Button::Button()
{
	ShowCursor(true); //to remove

	_d3ddev = &Engine::d3ddev;
	SetScale(1);

	_colorDefault = new D3DXCOLOR(1, 1, 1, 1);

	//Sprite Default
	_spriteDefault = new Sprite();
	_spriteDefault->SetTexture("Default.bmp");
	_spriteDefault->SetWidth(400);
	_spriteDefault->SetHeight(40);
	_spriteDefault->SetPosition(0, 0);
	_spriteDefault->SetSpriteColor(_colorDefault);

	//Sprite Over
	_spriteHover = new Sprite();
}

Button::~Button()
{

}

void Button::Update()
{
	HudElement::Update();
	DrawButton();
	Hover();
	OnClick();
}

void Button::Hover()
{
	//Check if the mouse is hover the sprite
}

void Button::OnClick()
{
	//Check if the mouse clicked & is over
}

void Button::DrawButton()
{
	_spriteDefault->Update();
	_spriteHover->Update();
}
