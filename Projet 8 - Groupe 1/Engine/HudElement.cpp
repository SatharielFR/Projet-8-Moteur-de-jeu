#include "pch.h"
#include "Framework.h"

HudElement::HudElement()
{
    //_nbWidth = SCREEN_WIDTH;
    //_nbHeight = SCREEN_HEIGHT;
    SetWidth(SCREEN_WIDTH);
    SetHeight(SCREEN_HEIGHT);
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
    _rec.left = _transform.m_vPos.x;
    _rec.top = _transform.m_vPos.y;
    _rec.right = _transform.m_vSca.x;
    _rec.bottom = _transform.m_vSca.y;
}

void HudElement::SetPosition(int x, int y)
{
    _transform.SetPosition((float)x, (float)y, 0);
}

D3DXVECTOR3 HudElement::GetPosition()
{
    return _transform.m_vPos;
}

float HudElement::GetWidth()
{
    return _transform.m_vSca.x;
}

float HudElement::GetHeight()
{
    return _transform.m_vSca.y;
}

void HudElement::SetWidth(float nbWidth)
{
    _transform.Scaling(nbWidth, _transform.m_vSca.y, _transform.m_vSca.z);
}

void HudElement::SetHeight(float nbHeight)
{
    _transform.Scaling(_transform.m_vSca.x, nbHeight, _transform.m_vSca.z);
}

void HudElement::SetScale(float fScale)
{
    _transform.ScalingUniforme(fScale);
}
