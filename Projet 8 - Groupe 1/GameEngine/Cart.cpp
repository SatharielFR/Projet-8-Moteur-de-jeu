#include "Cart.h"
#include "RailManager.h"

Cart::Cart(Scene* scene, RailManager* railManager)
{
    m_scene = scene;
    m_railManager = railManager;
    //Create the Cart
    m_entityCart = new Entity();
    m_scene->AddEntity(m_entityCart);
    MeshComponent* l_meshComponentCart = new MeshComponent();
    l_meshComponentCart->SetMeshAndTexturePath("..\\Ressources\\Cube.x");
    m_entityCart->AddComponent(l_meshComponentCart);
    //Init Cart position
    m_entityCart->transform->m_transform->Move(0.0f, 1.0f, 0.0f);
//    m_entityCart->transform->m_transform->Rotate(45.0f, 45.0f, 0.0f);
    m_entityCart->transform->m_transform->ScalingUniforme(0.01f);
}

Cart::~Cart()
{
}

void Cart::Update()
{
    if (m_currentRailEntity == nullptr)
    {
        l_newLocation = new D3DXVECTOR3();
        itRail = m_railManager->m_listEntityRails.begin();
        //Set reference to the first Rail of the list
        m_currentRailEntity = *itRail;
        _vec3LerpStart = &m_currentRailEntity->transform->m_transform->m_vPos;
        m_currentRailEntity = *(++itRail);
        _vec3LerpEnd= &m_currentRailEntity->transform->m_transform->m_vPos;
    }
    else
    {
        //When the lerp is complete
        if (_fLerpValue == 1)
        {
            //Set the new destination to the next rail
            if (itRail != --m_railManager->m_listEntityRails.end())
            {
                _vec3LerpStart = &m_currentRailEntity->transform->m_transform->m_vPos;
                ++itRail;
                m_currentRailEntity = *(itRail);
                _vec3LerpEnd = &m_currentRailEntity->transform->m_transform->m_vPos;
                _fLerpValue = 0;
            }
        }
    }

    //Increase lerp Value
    _fLerpValue = _fLerpValue + _fCartSpeed * Timer::s_inst->GetDeltaTime();
    if (_fLerpValue > 1) { _fLerpValue = 1; }

    //Lerp Values
    D3DXVec3Lerp(l_newLocation, _vec3LerpStart, _vec3LerpEnd, _fLerpValue);

    //Set New location
    m_entityCart->transform->m_transform->SetPosition( l_newLocation->x,
                                                       l_newLocation->y,
                                                       l_newLocation->z);
}

D3DXVECTOR3 Cart::GetCartPosition()
{
    return m_entityCart->transform->m_transform->m_vPos;
}
