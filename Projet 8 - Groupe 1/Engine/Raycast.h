#pragma once

class Raycast
{
	public :

		#pragma region PublicVariables
			D3DXVECTOR3 origin;
			D3DXVECTOR3 direction;
		#pragma endregion

		#pragma region PublicFunctions
			Raycast CalcPickingRay(int mouse_x, int mouse_y);
			void TransformRay(Raycast* ray, D3DXMATRIX* invertViewMatrix);
		#pragma endregion 

};

