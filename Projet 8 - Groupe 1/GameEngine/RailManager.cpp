#include "RailManager.h"

RailManager::RailManager()
{
    CreateMeshComponents();
}

RailManager::~RailManager()
{

}

void RailManager::Reset()
{
    m_nbPositionX = 0;
    m_nbPositionY = 0.01;
    m_nbPositionZ = 0;

    for (Entity* currentEntity : m_listEntityRails)
    {
        m_scene->DestroyEntity(currentEntity);
    }
    m_listEntityRails.clear();
}

void RailManager::CreateMeshComponents()
{
    _meshComponentRailsForward = new MeshComponent();
    _meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Forward.x");
    _meshComponentRailsTurn = new MeshComponent();
    _meshComponentRailsTurn->SetMeshAndTexturePath("..\\Ressources\\Rail-Right.x");
    _meshComponentRailsUp = new MeshComponent();
    _meshComponentRailsUp->SetMeshAndTexturePath("..\\Ressources\\Rail-Up.x");
}

void RailManager::CreateRails(Scene* scene)
{
    m_scene = scene;
    for (int i = 0; i < m_nbRailSize; i++)
    {
        //Create the rail
        Entity* l_entityCurrentRail = new Entity();
        m_scene->AddEntity(l_entityCurrentRail);
        l_entityCurrentRail->transform->m_transform->ScalingUniforme(m_fScale);

        //Select the rail Prefab
        switch(m_currentDirection)
        {
            case (enumDirection::North) :
            {
                int fRandom = rand() % 3 + 1 ;
                m_nbPositionZ = m_nbPositionZ - m_Lenght;
                switch (fRandom)
                {
                    case (1): //Straight forward
                    {
                        CreateStraightRails(90, l_entityCurrentRail);
                        m_currentDirection = enumDirection::North;                       
                        break;
                    }
                    case (2): //Turn Right
                    {
                        l_entityCurrentRail->AddComponent(_meshComponentRailsTurn);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 90, 0);
                        m_currentDirection = enumDirection::East;                   
                        break;
                    }
                    case (3): //Turn Left
                    {
                        l_entityCurrentRail->AddComponent(_meshComponentRailsTurn);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 180, 0);
                        m_currentDirection = enumDirection::West;
                        break;
                    }
                } 
                break;
            }
            case (enumDirection::East):
            {
                int fRandom = rand() % 2 + 1 ;
                m_nbPositionX = m_nbPositionX - m_Lenght;
                switch (fRandom)
                {
                    case (1): //Straight Right
                    {
                        l_entityCurrentRail->AddComponent(_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 0, 0);
                        m_currentDirection = enumDirection::East;
                        break;
                       
                    }
                    case (2): //Turn Left
                    {
                        l_entityCurrentRail->AddComponent(_meshComponentRailsTurn);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 270, 0);
                        m_currentDirection = enumDirection::North;
                        break;
                    }
                }
                break;
            }
            case (enumDirection::West):
            {
                int fRandom = rand() % 2 + 1;
                m_nbPositionX = m_nbPositionX + m_Lenght;
                switch (fRandom)
                {
                    case (1): //Straight Left
                    {
                        l_entityCurrentRail->AddComponent(_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 0, 0);
                        m_currentDirection = enumDirection::West;
                        break;
                    }
                    case (2): //Turn Right
                    {
                        l_entityCurrentRail->AddComponent(_meshComponentRailsTurn);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 0, 0);
                        m_currentDirection = enumDirection::North;
                        break;
                    }
                }
                break;
            }
        }
        //Add to the list of rails
        m_listEntityRails.push_back(l_entityCurrentRail);
        l_entityCurrentRail = nullptr;
        delete l_entityCurrentRail;
    }
}

void RailManager::CreateStraightRails(float fRotationAngleY, Entity* entity)
{
    int fRandom;
    bool bRailHasBeenCreated = false;
    while (!bRailHasBeenCreated)
    {

        float fRotationAngleZ = 0;
        fRandom = rand() % 3 + 1;
        switch (fRandom)
        {
            case (1):
            {
                fRotationAngleY += 180;
                m_nbPositionY = m_nbPositionY + m_Height / 2;
                entity->AddComponent(_meshComponentRailsUp);
                entity->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                entity->transform->m_transform->RotateAngle(0, fRotationAngleY, fRotationAngleZ);
                bRailHasBeenCreated = true;
                break;
            }
            case (2):
            {
                fRotationAngleZ += 0;
                entity->AddComponent(_meshComponentRailsForward);
                entity->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                entity->transform->m_transform->RotateAngle(0, fRotationAngleY, fRotationAngleZ);
                bRailHasBeenCreated = true;
                break;
            }
            case (3):
            {
                //Cant go downer than ground
                if (m_nbPositionY > 1)
                {
                    m_nbPositionY = m_nbPositionY - m_Height / 2;
                    entity->AddComponent(_meshComponentRailsUp);
                    entity->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                    entity->transform->m_transform->RotateAngle(0, fRotationAngleY, fRotationAngleZ);
                    bRailHasBeenCreated = true;
                }
                else
                {
                    bRailHasBeenCreated = false;
                }
                break;
            }
        }
    }

    switch (fRandom)
    {
        case (1):
        {
            m_nbPositionY = m_nbPositionY + m_Height/2;
            break;
        }
        case (2):
        {
            break;
        }
        case (3):
        {
            //Cant go downer than ground
            if (m_nbPositionY > 1)
            {
                m_nbPositionY = m_nbPositionY - m_Height/2;
            }
            break;
        }
    }
}
