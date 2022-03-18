#pragma once
//#include "framework.h"

class Mesh
{
public:

#pragma region variables
    DWORD _numMaterials;
    LPD3DXMESH _mesh;
    LPDIRECT3DTEXTURE9* _texture;
    D3DMATERIAL9* _material;
#pragma endregion

#pragma region Constructeur
    Mesh();
    Mesh(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material);
#pragma endregion

#pragma region methods
    void LoadMesh(Mesh* mesh, LPCTSTR file, LPDIRECT3DDEVICE9 device);
#pragma endregion

#pragma region accessors
    DWORD GetNumMaterials();
    LPD3DXMESH GetMesh();
    LPDIRECT3DTEXTURE9* GetTexture();
    D3DMATERIAL9* GetMaterial();
#pragma endregion

#pragma region mutators
    void SetNumMaterials(DWORD numMaterials);
    void SetMesh(LPD3DXMESH mesh);
    void SetTexture(LPDIRECT3DTEXTURE9* texture);
    void SetMaterial(D3DMATERIAL9* material);
#pragma endregion



};

