#pragma once
class Model
{
    public:

        DWORD numMaterials;
        LPD3DXMESH Mesh;
        LPDIRECT3DTEXTURE9* Texture;
        D3DMATERIAL9* Material;

        Model(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material);
        void LoadModel(Model* model, LPCTSTR File);

};

