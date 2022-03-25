#pragma once
class D3DXTRI3;

class Raycast
{
	public :
		D3DXVECTOR3 origin;
		D3DXVECTOR3 direction;

		Raycast CalcPickingRay(int mouse_x, int mouse_y);
		void TransformRay(Raycast* ray, D3DXMATRIX* invertViewMatrix);

};

