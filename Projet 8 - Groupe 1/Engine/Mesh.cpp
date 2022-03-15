#include "pch.h"
#include "framework.h"

Mesh::Mesh(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material)
{

    _numMaterials = materials;
    _mesh = mesh;
    _texture = texture;
    _material = material;
}

void Mesh::LoadMesh(Mesh* mesh, LPCTSTR File)
{
    //LPD3DXBUFFER bufMaterial;
    //D3DXLoadMeshFromXW(File, D3DXMESH_SYSTEMMEM, d3ddev, NULL, &bufMaterial, NULL,
    //    &mesh->_numMaterials, &mesh->_mesh);
    //OutputDebugString(L"LOAD MESH \n");

    //D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufMaterial->GetBufferPointer();
    //OutputDebugString(L"GET BUFFER\n");

    //mesh->_material = new D3DMATERIAL9[mesh->numMaterials];
    //mesh->_texture = new LPDIRECT3DTEXTURE9[mesh->numMaterials];

    //OutputDebugString(L"LOAD MESH \n");

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
