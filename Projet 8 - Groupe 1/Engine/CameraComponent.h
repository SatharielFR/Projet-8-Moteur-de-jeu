#pragma once


class CameraComponent : public Component
{
	public:
	#pragma region PublicVariables
		static int s_type;
		D3DXMATRIX matProjection;   // the projection transform matrix
	#pragma endregion

    #pragma region PublicFunctions
		CameraComponent();
		virtual void Begin();
		virtual void Render();
		virtual void Update();
		virtual int GetType() { return s_type; }
    #pragma endregion
};

