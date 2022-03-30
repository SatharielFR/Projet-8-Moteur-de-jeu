#pragma once
//#include "framework.h"

class MeshComponent : public Component
{
    public:

    #pragma region variables
        static int s_type;
        DWORD numMaterials;
        LPD3DXMESH mesh;
        LPDIRECT3DTEXTURE9* meshTextures;
        D3DMATERIAL9* meshMaterials;
        LPD3DXBUFFER materialBuffer;
        string meshAndTexturePath;
    #pragma endregion


    #pragma region Constructeur
        MeshComponent();
        MeshComponent(DWORD materials, LPD3DXMESH meshIn, LPDIRECT3DTEXTURE9* textureIn, D3DMATERIAL9* materialIn, string meshAndTexturePathIn);
        ~MeshComponent();
    #pragma endregion

    #pragma region methods
        void LoadMesh(LPCTSTR file, LPDIRECT3DDEVICE9 device);
    #pragma endregion

    #pragma region accessors
        DWORD GetNumMaterials();
        LPD3DXMESH GetMesh();
        string GetMeshAndTexturePath();
        const LPDIRECT3DTEXTURE9* GetMeshTextures();
        const D3DMATERIAL9* GetMeshMaterials();
        virtual int GetType() { return s_type; }
        bool IsMeshLoaded() { return _bIsMeshLoaded; }
    #pragma endregion

    #pragma region mutators
        void SetNumMaterials(DWORD numMaterials);
        void SetMesh(LPD3DXMESH mesh);
        void SetTexture(LPDIRECT3DTEXTURE9* texture);
        void SetMaterial(D3DMATERIAL9* material);
        void SetMeshAndTexturePath(string pathIn);
    #pragma endregion

    private :
        bool _bIsMeshLoaded = false;
        bool _bIsTextureLoaded = false;

};

