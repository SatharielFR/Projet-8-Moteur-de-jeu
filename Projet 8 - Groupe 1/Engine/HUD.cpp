#include "pch.h"
#include "framework.h"

//namespace Interface 
//{

	// https://www.gamedev.net/forums/topic/287779-menu-and-hud-with-dx9/

	HUD::HUD() {
		g_lpTexture = NULL;
		g_lpVBuffer = NULL;
	}


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
	}

	void HUD::AddSprite(Sprite* spriteToAdd)
	{
		_lstSprites.push_back(spriteToAdd);
	}

	void HUD::AddButton(Button* buttonToAdd)
	{
		_lstButtons.push_back(buttonToAdd);
	}

	void HUD::AddText(Text* textToAdd)
	{
		_lstTexts.push_back(textToAdd);
	}

	//UNTESTED AND PROBABLY INCOMPLETE
	void HUD::UpdateHUD(LPDIRECT3DDEVICE9 device) {
		//device->SetFVF(FVF_TLVERTEX);
		//device->SetStreamSource(0, g_lpVBuffer, 0, sizeof(TLVERTEX));
		//device->SetTexture(0, g_lpTexture);
		//device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

		// add images and text
		//draw all images
		//draw all texts
	}
//}