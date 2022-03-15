#pragma once
//#include "framework.h"

class Mesh
{
public:

    DWORD _numMaterials;
    LPD3DXMESH _mesh;
    LPDIRECT3DTEXTURE9* _texture;
    D3DMATERIAL9* _material;

    Mesh(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material);
    void LoadMesh(Mesh* mesh, LPCTSTR File);

};

