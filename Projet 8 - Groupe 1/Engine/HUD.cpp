#include "pch.h"
#include "framework.h"

// https://www.gamedev.net/forums/topic/287779-menu-and-hud-with-dx9/

HUD::HUD() {
	g_lpTexture = NULL;
	g_lpVBuffer = NULL;
}



		//UNTESTED AND PROBABLY INCOMPELTE
void HUD::InitializeHUD(LPDIRECT3DDEVICE9 device) {
	if (FAILED(device->CreateVertexBuffer(sizeof(TLVERTEX) * 4, 0, FVF_TLVERTEX, D3DPOOL_DEFAULT, &g_lpVBuffer, NULL))) 
	{ 
		//Somethings gone wrong! handle an error here and bail out gracefully
	}
		TLVERTEX* pData;
		g_lpVBuffer->Lock(0, 0, reinterpret_cast<void**>(&pData), 0);

		//creating quad coords
		float low_x = 0.0f;
		float low_y = 0.0f;
		float high_x = 5.0f;
		float high_y = 5.0f;
		//

		pData[0].p = D3DXVECTOR4(low_x, low_y, 0.0f, 1.0f);
		pData[1].p = D3DXVECTOR4(high_x, low_y, 0.0f, 1.0f);
		pData[2].p = D3DXVECTOR4(low_x, high_y, 0.0f, 1.0f);
		pData[3].p = D3DXVECTOR4(high_x, high_y, 0.0f, 1.0f);

		//we need to set the colours of the verticies; // colourpData[0].c =
		pData[1].c = pData[2].c = pData[3].c = D3DCOLOR_XRGB(255, 255, 255); //white
		pData[0].t = D3DXVECTOR2(0.0f, 0.0f);
		pData[1].t = D3DXVECTOR2(1.0f, 0.0f);
		pData[2].t = D3DXVECTOR2(0.0f, 1.0f);
		pData[3].t = D3DXVECTOR2(1.0f, 1.0f);
		g_lpVBuffer->Unlock();
}

//UNTESTED AND PROBABLY INCOMPLETE
void HUD::UpdateHUD(LPDIRECT3DDEVICE9 device) {
	device->SetFVF(FVF_TLVERTEX);
	device->SetStreamSource(0, g_lpVBuffer, 0, sizeof(TLVERTEX));
	device->SetTexture(0, g_lpTexture);
	device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}