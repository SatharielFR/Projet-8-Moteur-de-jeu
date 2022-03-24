#include "RailManager.h"

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
        switch(m_currentDirection)
        {
            case (enumDirection::Forward) :
            {
                break;
            }
            case (enumDirection::Backward):
            {
                break;
            }
            case (enumDirection::Right):
            {
                break;
            }
            case (enumDirection::Left):
            {
                break;
            }
        }

        m_nbPositionZ = m_nbPositionZ - m_Lenght;
        l_entityRails->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
        //Add to the list of rails
        m_listEntityRails.push_back(l_entityRails);
    }
}


void RailManager::RemoveRails()
{
    //To call after X sec to remove last rails from the list ans create one forward
}
