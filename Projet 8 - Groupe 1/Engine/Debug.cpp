#include "pch.h"
#include "framework.h"

Debug* Debug::s_inst = nullptr;

Debug::Debug(LPDIRECT3DDEVICE9* d3ddev)
{
    _d3ddev = d3ddev;
    Init();
}

void Debug::Init()
{
    //Singleton
    if (s_inst)
    {
        delete(this);
    }
    else
    {
        s_inst = this;
    }
    //Create font
    D3DXFONT_DESC fontDesc;
    ZeroMemory(&fontDesc, sizeof(D3DXFONT_DESC));
    fontDesc.Height = 25;
    fontDesc.Width = 12;
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

void Debug::DebugLog(const char charToLog[])
{
    string l_string;
    l_string = charToLog;
    DebugLog(&l_string);
}

void Debug::DebugLog(char charToLog[])
{
    string l_string;
    l_string = charToLog;
    DebugLog(&l_string);
}

void Debug::DebugLog(string* strToLog)
{
    //Create Rectangle to draw the font
    RECT  Rec;
    Rec.left = 20;
    Rec.top = 20;
    Rec.right = SCREEN_WIDTH;
    Rec.bottom = SCREEN_HEIGHT;

    //Display the font text using the rect and font
    _strToLog = std::wstring(strToLog->begin(), strToLog->end());
    const WCHAR* wcharTextToDisplay = _strToLog.c_str();
    LPCWSTR textToDisplay = LPCWSTR(wcharTextToDisplay);
    if (_Font)
    {
        _Font->DrawText(
                        NULL,
                        textToDisplay, // String to draw.
                        -1, // Null terminating string.
                        &Rec, // Rectangle to draw the string in.
                        DT_TOP | DT_LEFT, // Draw in top-left corner of rect.
                        0xff000000); // Black.
    }
}