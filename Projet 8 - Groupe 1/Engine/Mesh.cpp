#include "pch.h"
#include "framework.h"

Mesh::Mesh(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material)
{

    _numMaterials = materials;
    _mesh = mesh;
    _texture = texture;
    _material = material;
}

void Mesh::LoadMesh(Mesh* mesh, LPCTSTR file, LPDIRECT3DDEVICE9 device)
{
    // on passe le device par la scène et c'est elle qui va draw
    //LPD3DXBUFFER bufMaterial;
    //D3DXLoadMeshFromXW(file, D3DXMESH_SYSTEMMEM, d3ddev, NULL, &bufMaterial, NULL,
    //    &mesh->_numMaterials, &mesh->_mesh);
    //OutputDebugString(L"LOAD MESH \n");

    //D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufMaterial->GetBufferPointer();
    //OutputDebugString(L"GET BUFFER\n");

    //mesh->_material = new D3DMATERIAL9[mesh->numMaterials];
    //mesh->_texture = new LPDIRECT3DTEXTURE9[mesh->numMaterials];

    //for (DWORD index = 0; index < mesh->_numMaterials; index++)
    //{
    // this should be updated after renaming, probably broke
    //    mesh->Material[index] = tempMaterials[index].MatD3D;
    //    mesh->Material[index].Ambient = mesh->Material[index].Diffuse;

    //    // if there is a texture to load, load it 
    //    if (FAILED(D3DXCreateTextureFromFileA(d3ddev,
    //        tempMaterials[index].pTextureFilename,
    //        &mesh->Texture[index])))
    //        mesh->Texture[index] = NULL;    // if there is no texture, set the texture to NULL 
    //}

    return;
}

#pragma region Accessors
    DWORD Mesh::GetNumMaterials() {
        return _numMaterials;
    }

    LPD3DXMESH Mesh::GetMesh() {
        return _mesh;
    }

    LPDIRECT3DTEXTURE9* Mesh::GetTexture() {
        return _texture;
    }
    D3DMATERIAL9* Mesh::GetMaterial() {
        return _material;
    }
#pragma endregion

#pragma region mutators
    void Mesh::SetNumMaterials(DWORD numMaterials) {
        _numMaterials = numMaterials;
    }
    void Mesh::SetMesh(LPD3DXMESH mesh) {
        _mesh = mesh;
    }
    void Mesh::SetTexture(LPDIRECT3DTEXTURE9* texture) {
        _texture = texture;
    }
    void Mesh::SetMaterial(D3DMATERIAL9* material) {
        _material = material;
    }
#pragma endregion



    // NEED MUTATORS ???
    //https://www.unknowncheats.me/forum/d3d-tutorials-and-source/102186-d3d9-mesh-directx-format-loading-class.html
    //we are using this => https://stackoverflow.com/questions/996879/loading-mesh-from-x-file-with-direct-x-9-in-c