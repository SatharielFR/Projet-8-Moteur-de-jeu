#include "RailManager.h"
//#include "Entity.h"
//#include "Scene.h"
//#include "MeshComponent.h"
//#include "Component.h"
//#include "Transform.h"
//#include "transformComponent.h"

RailManager::RailManager()
{
}

RailManager::~RailManager()
{

}

void RailManager::CreateRails(Scene* scene)
{
    m_scene = scene;
    for (int i = 0; i < m_nbRailSize; i++)
    {
        //Create the rail
        Entity* l_entityRails = new Entity();
        m_scene->AddEntity(l_entityRails);
        MeshComponent* l_meshComponentRails = new MeshComponent();
        l_meshComponentRails->SetMeshAndTexturePath("..\\Ressources\\rail.x");
        l_entityRails->AddComponent(l_meshComponentRails);
        //Change Rail position
        l_entityRails->transform->m_transform->ScalingUniforme(m_fScale);
        l_entityRails->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
        m_nbPositionZ = m_nbPositionZ + m_Lenght;
        //Add to the list of rails
        m_listEntityRails.push_back(l_entityRails);
    }
}


void RailManager::RemoveRails()
{
}
