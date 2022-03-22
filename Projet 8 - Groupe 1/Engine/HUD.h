#pragma once

class HUD
{
public:
#pragma region Variables
	LPDIRECT3DVERTEXBUFFER9 g_lpVBuffer;
	LPDIRECT3DTEXTURE9 g_lpTexture;
#pragma endregion


#pragma region Constructeur
	HUD();
#pragma endregion


#pragma region methods
	void UpdateHUD(LPDIRECT3DDEVICE9 device);
	void InitializeHUD(LPDIRECT3DDEVICE9 device);

#pragma endregion



};

