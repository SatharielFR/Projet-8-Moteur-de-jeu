#include "pch.h"
#include "framework.h"

const DWORD CUSTOMVERTEX::FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1;

//Texture Tests
HRESULT Texturing::testTexture(LPDIRECT3DDEVICE9 device, LPCWSTR filePath) {
	IDirect3DTexture9* testTexture;
	D3DXCreateTextureFromFile(device, filePath, &testTexture);
	
	if (!testTexture) {
		return D3D_OK;
	}
	else {
		return D3DERR_NOTAVAILABLE;
	}
}