#include "pch.h"
#include "framework.h"

MeshComponent::MeshComponent(DWORD materials, LPD3DXMESH mesh, LPDIRECT3DTEXTURE9* texture, D3DMATERIAL9* material)
{

    _numMaterials = materials;
    _mesh = mesh;
    _texture = texture;
    _material = material;
}

MeshComponent::MeshComponent() {
    _numMaterials = 0;
    _mesh = 0;
    _texture = 0;
    _material = 0;
}

/// <summary>
/// this has to be tested, it probably does not work properly
/// this method should only be called in scene as we do not have access to the device (d3ddev) in this class
/// </summary>
/// <param name="mesh">mesh of the Mesh object</param>
/// <param name="file">filepath to .x file</param>
/// <param name="device">device to draw on PASSED BY SCENE</param>
void MeshComponent::LoadMesh(MeshComponent* mesh, LPCTSTR file, LPDIRECT3DDEVICE9 device)
{
     //on passe le device par la scène et c'est elle qui va draw
    LPD3DXBUFFER bufMaterial;
    D3DXLoadMeshFromXW(file, D3DXMESH_SYSTEMMEM, device, NULL, &bufMaterial, NULL, &mesh->_numMaterials, &mesh->_mesh);

    D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufMaterial->GetBufferPointer();

    mesh->_material = new D3DMATERIAL9[mesh->_numMaterials];
    mesh->_texture = new LPDIRECT3DTEXTURE9[mesh->_numMaterials];

    for (DWORD index = 0; index < mesh->_numMaterials; index++)
    {
     //this should be updated after renaming, probably broke
        mesh->_material[index] = tempMaterials[index].MatD3D;
        mesh->_material[index].Ambient = mesh->_material[index].Diffuse;

        // if there is a texture to load, load it 
        if (FAILED(D3DXCreateTextureFromFileA(device,
            tempMaterials[index].pTextureFilename,
            &mesh->_texture[index])))
            mesh->_texture[index] = NULL;    // if there is no texture, set the texture to NULL 
    }

    return;
}

#pragma region Accessors
    DWORD MeshComponent::GetNumMaterials() {
        return _numMaterials;
    }

    LPD3DXMESH MeshComponent::GetMesh() {
        return _mesh;
    }

    LPDIRECT3DTEXTURE9* MeshComponent::GetTexture() {
        return _texture;
    }
    D3DMATERIAL9* MeshComponent::GetMaterial() {
        return _material;
    }
#pragma endregion

#pragma region mutators
    void MeshComponent::SetNumMaterials(DWORD numMaterials) {
        _numMaterials = numMaterials;
    }
    void MeshComponent::SetMesh(LPD3DXMESH mesh) {
        _mesh = mesh;
    }
    void MeshComponent::SetTexture(LPDIRECT3DTEXTURE9* texture) {
        _texture = texture;
    }
    void MeshComponent::SetMaterial(D3DMATERIAL9* material) {
        _material = material;
    }
#pragma endregion

    //https://www.unknowncheats.me/forum/d3d-tutorials-and-source/102186-d3d9-mesh-directx-format-loading-class.html
    //we are using this => https://stackoverflow.com/questions/996879/loading-mesh-from-x-file-with-direct-x-9-in-c