#pragma once
class D3DXTRI3;

class Raycast
{
	public :
		bool RayTriIntersect(D3DXVECTOR3* pPoint, D3DXVECTOR3* pDir, D3DXTRI3* pTri, D3DXVECTOR3* pIntersect);
};

