#include "pch.h"
#include "framework.h"

MeshComponent::MeshComponent(DWORD materials, LPD3DXMESH meshIn, LPDIRECT3DTEXTURE9* textureIn, D3DMATERIAL9* materialIn, string meshAndTexturePathIn)
{

    numMaterials = materials;
    mesh = meshIn;
    meshTextures = textureIn;
    meshMaterials = materialIn;
    meshAndTexturePath = meshAndTexturePathIn;
    MeshComponent::id = 2;
}

MeshComponent::MeshComponent() {
    numMaterials = 0;
    mesh = NULL;
    meshTextures = NULL;
    meshMaterials = NULL;
    materialBuffer = NULL;
    meshAndTexturePath = "";
    MeshComponent::id = 2;
}

//easy debugs
//MessageBoxA(NULL, strFileName.c_str(), "", MB_OK);


/// <summary>
/// loads the mesh and creates the appropriate texture from a .x file
/// </summary>
/// <param name="file">|| filepath to the .x mesh file</param>
/// <param name="device">|| device of the engine, necessary to draw. This means that this method can only be called in engine render and not in class as it needs the device</param>
void MeshComponent::LoadMesh(LPCTSTR file, LPDIRECT3DDEVICE9 device)
{
    //loading mesh
    if (mesh == NULL)
    {

        HRESULT hr = D3DXLoadMeshFromX(file, D3DXMESH_SYSTEMMEM, device, NULL, &materialBuffer, NULL, &numMaterials, &mesh);

        // Loading the material buffer
        D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)materialBuffer->GetBufferPointer();
        // Holding material and texture pointers
        meshMaterials = new D3DMATERIAL9[numMaterials];
        meshTextures = new LPDIRECT3DTEXTURE9[numMaterials];
        // Filling material and texture arrays
        for (DWORD i = 0; i < numMaterials; i++)
        {
            // Copy the material
            meshMaterials[i] = d3dxMaterials[i].MatD3D;

            // Set the ambient color for the material (D3DX does not do this)
            meshMaterials[i].Ambient = meshMaterials[i].Diffuse;

            // Create the texture if it exists - it may not
            meshTextures[i] = NULL;
            if (d3dxMaterials[i].pTextureFilename) {

                //create full path
                string strFileName = "..\\Ressources\\";
                strFileName.append((string)d3dxMaterials[i].pTextureFilename);

                //store it in class variable
                meshAndTexturePath = strFileName;

                //making string to lpwstr for CreateTextureFromFile
                wstring stemp = wstring(strFileName.begin(), strFileName.end());
                LPCWSTR fullPath = stemp.c_str();

                //StringCchCatW(strFileName, 26, (d3dxMaterials[i].pTextureFilename));
                D3DXCreateTextureFromFile(device, fullPath, &meshTextures[i]);
            }
        }
        materialBuffer->Release();
    }
}

#pragma region Accessors
    DWORD MeshComponent::GetNumMaterials() {
        return numMaterials;
    }

    LPD3DXMESH MeshComponent::GetMesh() {
        return mesh;
    }

    const LPDIRECT3DTEXTURE9* MeshComponent::GetMeshTextures() {
        return meshTextures;
    }

    const D3DMATERIAL9* MeshComponent::GetMeshMaterials() {
        return meshMaterials;
    }

    string MeshComponent::GetMeshAndTexturePath() {
        return meshAndTexturePath;
    }
#pragma endregion

#pragma region mutators
    void MeshComponent::SetNumMaterials(DWORD numMaterials) {
        numMaterials = numMaterials;
    }
    void MeshComponent::SetMesh(LPD3DXMESH mesh) {
        mesh = mesh;
    }
    void MeshComponent::SetTexture(LPDIRECT3DTEXTURE9* texture) {
        meshTextures = texture;
    }
    void MeshComponent::SetMaterial(D3DMATERIAL9* material) {
        meshMaterials = material;
    }

    void MeshComponent::SetMeshAndTexturePath(string pathIn) {
        meshAndTexturePath = pathIn;
    }
#pragma endregion