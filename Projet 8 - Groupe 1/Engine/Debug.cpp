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

void Debug::ScreenLog(const char charToLog[])
{
    string l_string;
    l_string = charToLog;
    ScreenLog(&l_string);
}

void Debug::ScreenLog(char charToLog[])
{
    string l_string;
    l_string = charToLog;
    ScreenLog(&l_string);
}

void Debug::ScreenLog(string* strToLog)
{
    //Create the log
    Log* l_pLogCurrent = new Log(*strToLog, _fDefaultDuration);
    _lstLogs.push_back(l_pLogCurrent);
}

void Debug::UpdateScreenLogs()
{
    //if there is at least one Log on the list, Print the last log added to the list
    if (_lstLogs.size() > 0)
    {
        //Create Rectangle to draw the font
        RECT  Rec;
        Rec.left = 20;
        Rec.top = 20;
        Rec.right = SCREEN_WIDTH;
        Rec.bottom = SCREEN_HEIGHT;

        //Create the text to display
        string strToLog = "";
        for (Log* currentLog : _lstLogs)
        {
            strToLog =  currentLog->GetText() + "\n" + strToLog;
        }

        //Display the font text using the rect and font
        _wstrToLog = std::wstring(strToLog.begin(), strToLog.end());
        const WCHAR* wcharTextToDisplay = _wstrToLog.c_str();
        LPCWSTR textToDisplay = LPCWSTR(wcharTextToDisplay);
        if (_Font)
        {
            _Font->DrawText(
                NULL,
                textToDisplay, // String to draw.
                -1, // Null terminating string.
                &Rec, // Rectangle to draw the string in.
                DT_TOP | DT_LEFT, // Draw in top-left corner of rect.
                _DefaultColor); // Black.
        }

        //Update List
        auto it = _lstLogs.begin()++;
        while(it != _lstLogs.end())
        {
            if ((*it)->bShouldBeDestroy())
            {
                it = _lstLogs.erase(it);
            }

            else
            {
                ++it;
            }
        }
    }
}
