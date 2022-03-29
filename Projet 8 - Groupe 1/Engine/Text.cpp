#include "pch.h"
#include "Framework.h"

Text::Text()
{
    InitFont();
}

Text::~Text()
{
}

void Text::InitFont()
{
    _d3ddev = &Engine::d3ddev;

    //Create font
    D3DXFONT_DESC fontDesc;
    ZeroMemory(&fontDesc, sizeof(D3DXFONT_DESC));
    fontDesc.Height = 25 * _fFontSize;
    fontDesc.Width = 12 * _fFontSize;
    fontDesc.Weight = 500;
    fontDesc.MipLevels = D3DX_DEFAULT;
    fontDesc.Italic = false;
    fontDesc.CharSet = 0;
    fontDesc.OutputPrecision = 0;
    fontDesc.Quality = 0;
    fontDesc.PitchAndFamily = 0;
    char* test = (char*)fontDesc.FaceName;
    strcpy(test, "Times New Roman"); // font style
    D3DXCreateFontIndirect(*_d3ddev, &fontDesc, &_Font);
}

void Text::Update() 
{
    HudElement::Update();
    DrawTextOnScreen();
}

void Text::DrawTextOnScreen()
{
    //Display the font text using the rect and font
    _wstrTextToDisplay = std::wstring(_strText.begin(), _strText.end());
    const WCHAR* wcharTextToDisplay = _wstrTextToDisplay.c_str();
    LPCWSTR textToDisplay = LPCWSTR(wcharTextToDisplay);
    if (_Font)
    {
        _Font->DrawText(
            NULL,
            textToDisplay, // String to draw.
            -1, // Null terminating string.
            &_rec, // Rectangle to draw the string in.
            DT_TOP | DT_LEFT, // Draw in top-left corner of rect.
            _colorText); // Black.
    }
}

void Text::SetText(string strText)
{
    _strText = strText;
}

void Text::SetTextColor(D3DXCOLOR color)
{
    _colorText = color;
}

void Text::SetFontSize(float size)
{
    _fFontSize = size;
    InitFont();
}
