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
        1.0f,    // the near view-plane
        10000.0f);    // the far view-plane
}

void CameraComponent::Update()
{
    Render();
}


 void CameraComponent::Render()
{
    Component::Render();
    Engine::d3ddev->SetTransform(D3DTS_VIEW, &_entityParent->transform->m_transform->m_matrix);    // set the view transform to matView
    Engine::d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
}

