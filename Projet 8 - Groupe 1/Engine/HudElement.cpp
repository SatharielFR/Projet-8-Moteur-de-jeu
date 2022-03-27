#include "pch.h"
#include "Framework.h"

HudElement::HudElement()
{
    _nbPosX = 0;
    _nbPosY = 0;
    _nbWidth = SCREEN_WIDTH;
    _nbHeight = SCREEN_HEIGHT;
}

HudElement::~HudElement()
{
}

void HudElement::Update()
{
	DrawRec();
}

void HudElement::DrawRec()
{
    //Create Rectangle to draw the font
    _rec.left = _nbPosX;
    _rec.top = _nbPosY;
    _rec.right = _nbWidth;
    _rec.bottom = _nbHeight;
}

void HudElement::SetPosition(int x, int y)
{
    _nbPosX = x;
    _nbPosY = y;
}

void HudElement::SetWidth(int nbWidth)
{
    _nbWidth = nbWidth;
}

void HudElement::SetHeight(int nbHeight)
{
    _nbHeight = nbHeight;
}
