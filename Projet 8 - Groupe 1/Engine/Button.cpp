#include "pch.h"
#include "Framework.h"

Button::Button(Engine* engine)
{
	ShowCursor(true); //to remove

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
	_spriteDefault->SetTexture("Default.bmp");
	_spriteDefault->SetWidth(40);
	_spriteDefault->SetHeight(40);
	_spriteDefault->SetPosition(0, 0);
	_spriteHover->SetSpriteColor(_colorHover);
}

Button::~Button()
{

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

bool Button::IsMouseHover()
{
	//Check if the mouse is hover the sprite
	POINT point;
	if (GetCursorPos(&point))
	{

		int l_nbAnchorPositionX = 0, l_nbAnchorPositionY = 0;

		RECT rect;

		if (GetWindowRect(_engine->getHwnd(), &rect))
		{
			l_nbAnchorPositionX = rect.left;
			l_nbAnchorPositionY = rect.top;
		}

		int l_mousePosX = point.x ;//+ l_nbAnchorPositionX;
		int l_mousePosY = point.y ;//+ l_nbAnchorPositionY;

		bool bIsInX= false;
		bool bIsInY= false;

		if (l_mousePosX > _spriteDefault->GetPosition().x && l_mousePosX < _spriteDefault->GetPosition().x + TEXTURE_SIZE*_spriteDefault->GetWidth() )
		{
			bIsInX = true;
		}
		if (l_mousePosY > _spriteDefault->GetPosition().y && l_mousePosY < _spriteDefault->GetPosition().y + TEXTURE_SIZE * _spriteDefault->GetHeight())
		{
			bIsInY = true;
		}

		if (bIsInX && bIsInY)
		{
			return true;
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
			Debug::s_inst->ScreenLog("Click", 1.0f);
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
