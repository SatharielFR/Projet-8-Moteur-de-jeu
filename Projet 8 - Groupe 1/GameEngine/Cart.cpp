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
        itRail = m_railManager->m_listEntityRails.begin();
        //Set reference to the first Rail of the list
        m_currentRailEntity = *(++itRail);
    }
    else
    {
        //Update the current Rail Target according to rail position in Z
        if ( itRail != --m_railManager->m_listEntityRails.end())
        {
            ++itRail;
        }

        m_currentRailEntity = *(itRail);
    }

    //Move the Cart Transform
    m_entityCart->transform->m_transform->SetPosition(  m_currentRailEntity->transform->m_transform->m_vPos.x,
                                                        m_currentRailEntity->transform->m_transform->m_vPos.y,
                                                        m_currentRailEntity->transform->m_transform->m_vPos.z   );
}

D3DXVECTOR3 Cart::GetCartPosition()
{
    return m_entityCart->transform->m_transform->m_vPos;
}
