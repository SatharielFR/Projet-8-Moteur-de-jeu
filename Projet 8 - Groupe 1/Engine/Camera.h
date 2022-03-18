#pragma once


class Camera : public Component
{
	public:
	#pragma region PublicVariables
		D3DXMATRIX matProjection;   // the projection transform matrix
		LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
	#pragma endregion

    #pragma region PublicFunctions
		Camera();
		virtual void Begin();
		virtual void Render();
		virtual void Update();
    #pragma endregion
};

