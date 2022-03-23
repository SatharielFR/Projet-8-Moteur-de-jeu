#include "pch.h"
#include "framework.h"

// https://www.gamedev.net/forums/topic/287779-menu-and-hud-with-dx9/

HUD::HUD() {
	g_lpTexture = NULL;
	g_lpVBuffer = NULL;
	_rec = RECT();
}



		//UNTESTED AND PROBABLY INCOMPELTE
void HUD::InitializeHUD(LPDIRECT3DDEVICE9 device) {
	//REMOVING THIS IF BREAKS EVERYTHING I DONT KNOW WHY
	if (FAILED(device->CreateVertexBuffer(sizeof(TLVERTEX) * 4, 0, FVF_TLVERTEX, D3DPOOL_DEFAULT, &g_lpVBuffer, NULL))) 
	{ 
		//Somethings gone wrong! handle an error here and bail out gracefully
	}

	//this creates a basic quad 
		TLVERTEX* pData;
		g_lpVBuffer->Lock(0, 0, reinterpret_cast<void**>(&pData), 0);

		//creating quad coords
		float low_x = SCREEN_WIDTH * 0.25;
		float high_x = SCREEN_WIDTH * 0.75;
		float low_y = 0;
		float high_y = SCREEN_WIDTH * 0.05;
		//


		pData[0].p = D3DXVECTOR4(low_x, low_y, 0.0f, 1.0f);
		pData[1].p = D3DXVECTOR4(high_x, low_y, 0.0f, 1.0f);
		pData[2].p = D3DXVECTOR4(low_x, high_y, 0.0f, 1.0f);
		pData[3].p = D3DXVECTOR4(high_x, high_y, 0.0f, 1.0f);

		//we need to set the colours of the verticies; // colourpData[0].c =
		pData[1].c = pData[2].c = pData[3].c = D3DCOLOR_XRGB(0, 0, 0); //white
		pData[0].t = D3DXVECTOR2(0.0f, 0.0f);
		pData[1].t = D3DXVECTOR2(1.0f, 0.0f);
		pData[2].t = D3DXVECTOR2(0.0f, 1.0f);
		pData[3].t = D3DXVECTOR2(1.0f, 1.0f);
		g_lpVBuffer->Unlock();
	//

		//create font
		CreateHUDFont(&device);

		//create margins for better display
		int lowXToGive, highXToGive, lowYToGive, highYToGive;
		lowXToGive = (int)low_x;
		highXToGive = (int)high_x;
		lowYToGive = (int)low_y;
		highYToGive = (int)high_y;
		//create Rect to display in
		CreateRectForDisplay(lowXToGive, highXToGive, lowYToGive, highYToGive);


}

//UNTESTED AND PROBABLY INCOMPLETE
void HUD::UpdateHUD(LPDIRECT3DDEVICE9 device) {
	device->SetFVF(FVF_TLVERTEX);
	device->SetStreamSource(0, g_lpVBuffer, 0, sizeof(TLVERTEX));
	device->SetTexture(0, g_lpTexture);
	device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	// add images and text
	//draw all images
	//draw all texts
}

void HUD::DisplayText(string* strToDisplay, float fDuration) {
	RECT newRec;
	newRec.left = 20;
	newRec.top = 20;
	newRec.right = SCREEN_WIDTH;
	newRec.bottom = SCREEN_HEIGHT;

	//Create the text to display
	string finalStrToLog = *strToDisplay;

	//Display the font text using the rect and font
	_wstrToLog = std::wstring(finalStrToLog.begin(), finalStrToLog.end());
	const WCHAR* wcharTextToDisplay = _wstrToLog.c_str();
	LPCWSTR textToDisplay = LPCWSTR(wcharTextToDisplay);
	if (_Font)
	{
		_Font->DrawText(
			NULL,
			textToDisplay, // String to draw.
			-1, // Null terminating string.
			&newRec, // Rectangle to draw the string in.
			DT_TOP | DT_LEFT, // Draw in top-left corner of rect.
			_DefaultColor); // Black.
	}
}

void HUD::CreateHUDFont(LPDIRECT3DDEVICE9* device) {
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
	D3DXCreateFontIndirect(*device, &fontDesc, &_Font);
}

void HUD::DisplayInt(int intToDisplay, float fDuration) {

	//Create the text to display
	string finalStrToLog = to_string(intToDisplay);

	//Display the font text using the rect and font
	_wstrToLog = std::wstring(finalStrToLog.begin(), finalStrToLog.end());
	const WCHAR* wcharTextToDisplay = _wstrToLog.c_str();
	LPCWSTR textToDisplay = LPCWSTR(wcharTextToDisplay);
	if (_Font)
	{
		_Font->DrawText(
			NULL,
			textToDisplay, // String to draw.
			-1, // Null terminating string.
			&_rec, // Rectangle to draw the string in.
			DT_TOP | DT_LEFT, // Draw in top-left corner of rect.
			_DefaultColor); // Black.
	}
}

void HUD::CreateRectForDisplay(int leftIn, int rightIn, int topIn, int bottomIn) {
	//Create Rectangle to draw the font
	RECT  Rec;
	Rec.left = leftIn;
	Rec.top = topIn;
	Rec.right = rightIn;
	Rec.bottom = bottomIn;

	_rec = Rec;
}

RECT HUD::getRect() {
	return _rec;
}