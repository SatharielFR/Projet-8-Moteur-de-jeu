#include "pch.h"
#include "framework.h"

Button::Button(Engine* engine)
{
	_engine = engine;
	_d3ddev = &Engine::d3ddev;
	SetScale(1);

	_colorDefault = new D3DXCOLOR(1, 1, 1, 1);
	_colorHover = new D3DXCOLOR(1, 0, 0, 1);

	//Sprite Default
	_spriteDefault = new Sprite();
	_spriteDefault->SetTexture("Default.bmp");
	_spriteDefault->SetWidth(40);
	_spriteDefault->SetHeight(40);
	_spriteDefault->SetPosition(0, 0);
	_spriteDefault->SetSpriteColor(_colorDefault);

	//Sprite Over
	_spriteHover = new Sprite();
	_spriteHover->SetTexture("Default.bmp");
	_spriteHover->SetWidth(40);
	_spriteHover->SetHeight(40);
	_spriteHover->SetPosition(0, 0);
	_spriteHover->SetSpriteColor(_colorHover);
}

Button::~Button()
{
	delete _spriteDefault;
}

void Button::Update()
{
	HudElement::Update();
	DrawButton();
	OnClick();
}

void Button::SetWidth(float fWidth)
{
	HudElement::SetWidth(fWidth);
	_spriteDefault->SetWidth(fWidth);
	_spriteHover->SetWidth(fWidth);
}

void Button::SetHeight(float fHeight)
{
	HudElement::SetHeight(fHeight);
	_spriteDefault->SetHeight(fHeight);
	_spriteHover->SetHeight(fHeight);
}

void Button::SetPosition(int x, int y)
{
	HudElement::SetPosition(x, y);
	_spriteDefault->SetPosition(x,y);
	_spriteHover->SetPosition(x, y);
}

void Button::SetDefaultColor(D3DXCOLOR* color)
{
	_colorDefault = color;
	_spriteDefault->SetSpriteColor(_colorDefault);
}

void Button::SetHoverColor(D3DXCOLOR* color)
{
	_colorHover = color;
	_spriteHover->SetSpriteColor(_colorHover);
}

void Button::SetTexture(string a, string b)
{
	_spriteDefault->SetTexture(a);
	_spriteHover->SetTexture(b);
}

void Button::SetTextureResolution(int x, int y)
{
	_spriteDefault->SetTextureSize(x,y);
	_spriteHover->SetTextureSize(x, y);
}

bool Button::IsMouseHover()
{
	//Check if the mouse is hover the sprite
	POINT point;
	if (GetCursorPos(&point))
	{
		if (ScreenToClient(GetEngine()->getHwnd(), &point)) {

			int l_mousePosX = point.x;
			int l_mousePosY = point.y;

			bool bIsInX = false;
			bool bIsInY = false;

			if (l_mousePosX > _spriteDefault->GetPosition().x + (_spriteDefault->GetTextureSize().x * _spriteDefault->GetWidth())/2 &&
				l_mousePosX < _spriteDefault->GetPosition().x + (_spriteDefault->GetTextureSize().x * _spriteDefault->GetWidth()) *2)
			{
				bIsInX = true;
			}
			if (l_mousePosY > _spriteDefault->GetPosition().y + (_spriteDefault->GetTextureSize().y * _spriteDefault->GetHeight()) &&
				l_mousePosY < _spriteDefault->GetPosition().y + (_spriteDefault->GetTextureSize().y * _spriteDefault->GetHeight()) *3)
			{
				bIsInY = true;
			}

			if (bIsInX && bIsInY)
			{
				return true;
			}
		}
	}

	return false;
}

void Button::OnClick()
{
	//Check if the mouse clicked & is over
	if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
	{
		if (IsMouseHover())
		{
			m_OnClic();
		}
	}
}

void Button::DrawButton()
{
	if (IsMouseHover())
	{
		_spriteHover->Update();
	}
	else
	{
		_spriteDefault->Update();
	}
}
