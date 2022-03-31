#include "pch.h"
#include "framework.h"

int MeshComponent::s_type = 2;

MeshComponent::MeshComponent(DWORD materials, LPD3DXMESH meshIn, LPDIRECT3DTEXTURE9* textureIn, D3DMATERIAL9* materialIn, string meshAndTexturePathIn)
{
    m_numMaterials = materials;
    m_mesh = meshIn;
    m_meshTextures = textureIn;
    m_meshMaterials = materialIn;
    m_strMeshAndTexturePath = meshAndTexturePathIn;
    m_materialBuffer->Release();
}

MeshComponent::MeshComponent() {
    m_numMaterials = 0;
    m_mesh = NULL;
    m_meshTextures = NULL;
    m_meshMaterials = NULL;
    m_materialBuffer = NULL;
    m_strMeshAndTexturePath = "";
}

MeshComponent::~MeshComponent()
{
    m_mesh->Release();
    m_materialBuffer->Release();

    delete m_meshTextures;
    delete m_meshMaterials;
}


/// <summary>
/// loads the mesh and creates the appropriate texture from a .x file
/// </summary>
/// <param name="file">|| filepath to the .x mesh file</param>
/// <param name="device">|| device of the engine, necessary to draw. This means that this method can only be called in engine render and not in class as it needs the device</param>
void MeshComponent::LoadMesh(LPCTSTR file, LPDIRECT3DDEVICE9 device)
{
    //loading mesh
    if (m_mesh == NULL)
    {
        HRESULT hr = D3DXLoadMeshFromX(file, D3DXMESH_SYSTEMMEM, device, NULL, &m_materialBuffer, NULL, &m_numMaterials, &m_mesh);

        // Loading the material buffer
        D3DXMATERIAL* l_d3dxMaterials = (D3DXMATERIAL*)m_materialBuffer->GetBufferPointer();
        // Holding material and texture pointers
        m_meshMaterials = new D3DMATERIAL9[m_numMaterials];
        m_meshTextures = new LPDIRECT3DTEXTURE9[m_numMaterials];
        // Filling material and texture arrays
        for (DWORD i = 0; i < m_numMaterials; i++)
        {
            // Copy the material
            m_meshMaterials[i] = l_d3dxMaterials[i].MatD3D;

            // Set the ambient color for the material (D3DX does not do this)
            m_meshMaterials[i].Ambient = m_meshMaterials[i].Diffuse;

            // Create the texture if it exists - it may not
            m_meshTextures[i] = NULL;
            if (l_d3dxMaterials[i].pTextureFilename) {

                //create full path
                string strFileName = "Ressources\\";
                strFileName.append((string)l_d3dxMaterials[i].pTextureFilename);

                //store it in class variable
                m_strMeshAndTexturePath = strFileName;

                //making string to lpwstr for CreateTextureFromFile
                wstring stemp = wstring(strFileName.begin(), strFileName.end());
                LPCWSTR fullPath = stemp.c_str();

                //StringCchCatW(strFileName, 26, (d3dxMaterials[i].pTextureFilename));
                D3DXCreateTextureFromFile(device, fullPath, &m_meshTextures[i]);
            }

            _bIsMeshLoaded = true;
            _bIsTextureLoaded = true;
        }
        m_materialBuffer->Release();
        l_d3dxMaterials = nullptr;
        delete l_d3dxMaterials;
    }
}

#pragma region Accessors
    DWORD MeshComponent::GetNumMaterials() {
        return m_numMaterials;
    }

    LPD3DXMESH MeshComponent::GetMesh() {
        return m_mesh;
    }

    const LPDIRECT3DTEXTURE9* MeshComponent::GetMeshTextures() {
        return m_meshTextures;
    }

    const D3DMATERIAL9* MeshComponent::GetMeshMaterials() {
        return m_meshMaterials;
    }

    string MeshComponent::GetMeshAndTexturePath() {
        return m_strMeshAndTexturePath;
    }
#pragma endregion

#pragma region mutators
    void MeshComponent::SetNumMaterials(DWORD m_numMaterials) {
        m_numMaterials = m_numMaterials;
    }
    void MeshComponent::SetMesh(LPD3DXMESH m_mesh) {
        m_mesh = m_mesh;
    }
    void MeshComponent::SetTexture(LPDIRECT3DTEXTURE9* texture) {
        m_meshTextures = texture;
    }
    void MeshComponent::SetMaterial(D3DMATERIAL9* material) {
        m_meshMaterials = material;
    }

    void MeshComponent::SetMeshAndTexturePath(string pathIn) {
        m_strMeshAndTexturePath = pathIn;
    }
#pragma endregion