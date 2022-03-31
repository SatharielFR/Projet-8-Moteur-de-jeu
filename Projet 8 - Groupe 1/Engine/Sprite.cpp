#include "pch.h"
#include "Framework.h"

Sprite::Sprite()
{
	_colorSprite = new D3DXCOLOR(255, 255, 255, 255);
	_d3ddev = &Engine::d3ddev;
    SetTexture("DefaultTexture.bmp");
    SetScale(1);
    _vec2TextureSize = new D3DXVECTOR2(1024, 1024);
}

Sprite::~Sprite()
{
    delete _vec2TextureSize;
}

void Sprite::Update()
{
	HudElement::Update();
	DrawSprite();
}

void Sprite::SetTexture(string strTextureName)
{
    //create full path
    string strFileName = "Ressources\\";
    strFileName.append((string)strTextureName);

    //making string to lpwstr for CreateTextureFromFile
    wstring stemp = wstring(strFileName.begin(), strFileName.end());
    LPCWSTR fullPath = stemp.c_str();

    D3DXCreateTextureFromFile(*_d3ddev, fullPath, &_text);

    //D3DXIMAGE_INFO info;
    //D3DXGetImageInfoFromFile(fullPath, &info);
    //D3DXCreateTextureFromFileEx(*_d3ddev,
    //                            fullPath,
    //                            TEXTURE_SIZE,
    //                            TEXTURE_SIZE,
    //                            info.MipLevels,
    //                            0,
    //                            info.Format,
    //                            D3DPOOL_DEFAULT,
    //                            D3DX_DEFAULT,
    //                            D3DX_DEFAULT,
    //                            0xFF000000,
    //                            &info,
    //                            NULL,
    //                            &_text);
}

void Sprite::DrawSprite()
{
	D3DXCreateSprite(*_d3ddev, &_sprite);
    _sprite->SetTransform(&_transform.m_matrix);
    _sprite->Begin(D3DXSPRITE_ALPHABLEND);
    _sprite->Draw(_text, NULL, NULL, &_transform.m_vPos, *_colorSprite);
    _sprite->End();
    _sprite->Release();
}

void Sprite::SetSpriteColor(D3DXCOLOR* color)
{
    _colorSprite = color;
}

void Sprite::SetWidth(float nbWidth)
{
    HudElement::SetWidth(nbWidth /_vec2TextureSize->x);
}

void Sprite::SetHeight(float nbHeight)
{
    HudElement::SetHeight(nbHeight/ _vec2TextureSize->y);
}

void Sprite::SetScale(float fScale)
{
    HudElement::SetScale(fScale / _vec2TextureSize->x);
}
