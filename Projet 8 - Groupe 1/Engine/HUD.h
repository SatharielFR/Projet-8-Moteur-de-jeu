#pragma once

class HUD
{
	public:
		#pragma region Variables
			LPDIRECT3DVERTEXBUFFER9 g_lpVBuffer;
			LPDIRECT3DTEXTURE9 g_lpTexture;
			ID3DXFont* _Font = 0;
			std::wstring _wstrToLog;
			list<Log*> _lstLogs;
			float _fDefaultDuration = 3.0f;
			D3DCOLOR _DefaultColor = D3DXCOLOR(255, 240, 0, 1);
			RECT _rec;
		#pragma endregion

		#pragma region Constructeur
			HUD();
		#pragma endregion

		#pragma region methods
			void UpdateHUD(LPDIRECT3DDEVICE9 device);
			void InitializeHUD(LPDIRECT3DDEVICE9 device);
			void DisplayText(string* strToDisplay, float fDuration = -1);
			void DisplayInt(int intToDisplay, float fDuration = -1);
			void CreateHUDFont(LPDIRECT3DDEVICE9* device);
			//create rect for display and make it match the blackbox
			void CreateRectForDisplay(int leftIn, int rightIn, int topIn, int bottomIn);
			RECT getRect();
		#pragma endregion
};

