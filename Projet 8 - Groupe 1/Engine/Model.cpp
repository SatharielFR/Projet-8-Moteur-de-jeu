#include "pch.h"
#include "framework.h"

Model::Model(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material)
{
    materials = numMaterials;
    mesh = Mesh;
    texture = Texture;
    material = Material;
}

void Model::LoadModel(Model* model, LPCTSTR File)
{
    //LPD3DXBUFFER bufMaterial;
    //D3DXLoadMeshFromXW(File, D3DXMESH_SYSTEMMEM, d3ddev, NULL, &bufMaterial, NULL,
    //    &model->numMaterials, &model->Mesh);
    //OutputDebugString(L"LOAD MESH \n");

    //D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufMaterial->GetBufferPointer();
    //OutputDebugString(L"GET BUFFER\n");

    //model->Material = new D3DMATERIAL9[model->numMaterials];
    //model->Texture = new LPDIRECT3DTEXTURE9[model->numMaterials];

    //OutputDebugString(L"LOAD MESH \n");

    //for (DWORD index = 0; index < model->numMaterials; index++)
    //{
    //    model->Material[index] = tempMaterials[index].MatD3D;
    //    model->Material[index].Ambient = model->Material[index].Diffuse;

    //    // if there is a texture to load, load it 
    //    if (FAILED(D3DXCreateTextureFromFileA(d3ddev,
    //        tempMaterials[index].pTextureFilename,
    //        &model->Texture[index])))
    //        model->Texture[index] = NULL;    // if there is no texture, set the texture to NULL 
    //}

    //return;
}
