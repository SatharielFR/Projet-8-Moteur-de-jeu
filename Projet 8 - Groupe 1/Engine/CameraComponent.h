#pragma once

class CameraComponent : public Component
{
	public:
	#pragma region PublicVariables
		static int s_type;
		D3DXMATRIX matProjection;   // the projection transform matrix
		D3DXVECTOR3 origin;
		D3DXVECTOR3 direction;
	#pragma endregion

    #pragma region PublicFunctions
		CameraComponent();
		virtual void Begin();
		virtual void Render();
		virtual void Update();
		virtual int GetType() { return s_type; }
		void CalcPickingRay();
    #pragma endregion
};

