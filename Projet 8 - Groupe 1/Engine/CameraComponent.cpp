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
    CalcPickingRay();
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
   Engine::d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
}

 void CameraComponent::CalcPickingRay()
 {
     D3DXMATRIX view;
     Engine::d3ddev->GetTransform(D3DTS_VIEW, &view);

     D3DXMATRIX viewInverse;
     D3DXMatrixInverse(&viewInverse, NULL, &view);

     origin.x = viewInverse._41;
     origin.y = viewInverse._42;
     origin.z = viewInverse._43;

     direction.x = viewInverse._31;
     direction.y = viewInverse._32;
     direction.z = viewInverse._33;

     D3DXVec3Normalize(&direction, &direction);
 }

 