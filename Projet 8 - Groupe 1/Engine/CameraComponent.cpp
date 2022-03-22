#include "pch.h"
#include "framework.h"

int CameraComponent::s_type = 3;

CameraComponent::CameraComponent() 
{
    Begin();
}

void CameraComponent::Begin()
{
    Component::Begin();
    
    // set the projection transform
    D3DXMatrixPerspectiveFovLH(&matProjection,
        D3DXToRadian(45),    // the horizontal field of view
        (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT, // aspect ratio
        0.01f,    // the near view-plane
        1000000.0f);    // the far view-plane
}

void CameraComponent::Update()
{
    Render();
}


 void CameraComponent::Render()
{ 
    Component::Render();

   D3DXMATRIX l_matrixView;
   D3DXVECTOR3 lookAt = _entityParent->transform->m_transform->m_vDir + _entityParent->transform->m_transform->m_vPos;
   D3DXMatrixLookAtLH( &l_matrixView,
                       &_entityParent->transform->m_transform->m_vPos,
                       &lookAt,
                       &_entityParent->transform->m_transform->m_vUp);
   Engine::d3ddev->SetTransform(D3DTS_VIEW, &l_matrixView);

    //Engine::d3ddev->SetTransform(D3DTS_VIEW, &_entityParent->transform->m_transform->m_matrix);    // set the view transform to matView
    Engine::d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
}

 