#pragma once

class HudElement
{
	public:
		#pragma region PublicMethods
			HudElement();
			~HudElement();
			virtual void Update();
			void DrawRec();
			virtual void SetWidth(float nbWidth);
			virtual void SetHeight(float nbHeight);
			virtual void SetScale(float fScale);
			virtual void SetPosition(int x, int y);
			//TODO : Set Anchor mode ( top-left, top,  top-right, left, center , right , bottom - left, ... )
		#pragma endregion 

		#pragma region Accessors
			D3DXVECTOR3 GetPosition();
			float GetWidth();
			float GetHeight();
		#pragma endregion

	protected:
		#pragma region PrivateVariables
			LPDIRECT3DDEVICE9* _d3ddev;				// the pointer to the device class
			//Color
			D3DCOLOR _colorRec = D3DXCOLOR(255, 240, 0, 1);
			//Position
			Transform _transform;
			RECT _rec;
		#pragma endregion
};

