#pragma once

class HudElement
{
	public:
		#pragma region PublicMethods
			HudElement();
			~HudElement();
			virtual void Update();
			void DrawRec();
			void SetPosition(int x, int y);
			void SetWidth(int nbWidth);
			void SetHeight(int nbHeight);
			//TODO : Set Anchor mode ( top-left, top,  top-right, left, center , right , bottom - left, ... )
		#pragma endregion 

	protected:
		#pragma region PrivateVariables
			LPDIRECT3DDEVICE9* _d3ddev;				// the pointer to the device class
			//Color
			D3DCOLOR _colorRec = D3DXCOLOR(255, 240, 0, 1);
			//Position
			RECT _rec;
			int _nbPosX;
			int _nbPosY;
			int _nbWidth;
			int _nbHeight;
		#pragma endregion
};

