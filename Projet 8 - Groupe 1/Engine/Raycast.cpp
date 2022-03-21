#include "pch.h"
#include "framework.h"

bool Raycast::RayTriIntersect(D3DXVECTOR3* pPoint, D3DXVECTOR3* pDir, D3DXTRI3* pTri, D3DXVECTOR3* pIntersect)
{
    /*D3DXVECTOR3 ab = pTri->v2 - pTri->v1;
    D3DXVECTOR3 ac = pTri->v3 - pTri->v1;
    D3DXVECTOR3 qp = -*pDir;
    D3DXVECTOR3 n;
    D3DXVec3Cross(&n, &ab, &ac);
    FLOAT d = D3DXVec3Dot(&qp, &n);
    if (d <= 0.0f)
        return false;
    D3DXVECTOR3 ap = *pPoint - pTri->v1;
    FLOAT t = D3DXVec3Dot(&ap, &n);
    if (t < 0.0f)
        return false;
    D3DXVECTOR3 e;
    D3DXVec3Cross(&e, &qp, &ap);
    FLOAT v = D3DXVec3Dot(&ac, &e);
    if (v<0.0f || v>d)
        return false;
    FLOAT w = -D3DXVec3Dot(&ab, &e);
    if (w<0.0f || v + w>d)
        return false;
    if (pIntersect == NULL)
        return true;
    FLOAT ood = 1.0f / d;
    t *= ood;
    v *= ood;
    w *= ood;
    *pIntersect = pTri->v1 * (1.0f - v - w);
    *pIntersect += pTri->v2 * v;
    *pIntersect += pTri->v3 * w;*/
    return true;
}
