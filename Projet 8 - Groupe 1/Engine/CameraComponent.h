#pragma once


class CameraComponent : public Component
{
	public:
	#pragma region PublicVariables
		static int s_type;
		D3DXMATRIX matProjection;   // the projection transform matrix
		LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
	#pragma endregion

    #pragma region PublicFunctions
		CameraComponent();
		virtual void Begin();
		virtual void Render();
		virtual void Update();
		virtual int GetType() { return s_type; }
    #pragma endregion
};

