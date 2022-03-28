#include "pch.h"
#include "Framework.h"

Sprite::Sprite()
{
	_colorSprite = new D3DXCOLOR(255, 255, 255, 255);
	_d3ddev = &Engine::d3ddev;
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
	HudElement::Update();
	DrawSprite();
}

void Sprite::SetTexture(string strTextureName)
{
    //create full path
    string strFileName = "..\\Ressources\\";
    strFileName.append((string)strTextureName);

    //making string to lpwstr for CreateTextureFromFile
    wstring stemp = wstring(strFileName.begin(), strFileName.end());
    LPCWSTR fullPath = stemp.c_str();

    D3DXCreateTextureFromFile(*_d3ddev, fullPath, &_text);
}

void Sprite::DrawSprite()
{
	D3DXCreateSprite(*_d3ddev, &_sprite);

    _sprite->SetTransform(&_transform.m_matrix);

    _sprite->Begin(D3DXSPRITE_ALPHABLEND);
    //_sprite->Draw(_text, &_rec, NULL, &_transform.m_vPos, *_colorSprite);

    D3DXVECTOR3 vec3Position = _transform.m_vPos;
    vec3Position.x = vec3Position.x * _transform.m_vSca.x;
    vec3Position.y = vec3Position.y * _transform.m_vSca.y;

    _sprite->Draw(_text, NULL, NULL, &vec3Position, *_colorSprite);
    _sprite->End();
}

void Sprite::SetScale(float fScale)
{
    _transform.ScalingUniforme(fScale);
}

void Sprite::SetPosition(int x, int y)
{
    _transform.SetPosition(x, y, 0);
}

void Sprite::SetSpriteColor(D3DXCOLOR* color)
{
    _colorSprite = color;
}
