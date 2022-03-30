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
        Entity* l_entityCurrentRail = new Entity();
        m_scene->AddEntity(l_entityCurrentRail);
        MeshComponent* l_meshComponentRailsForward = new MeshComponent();
        l_entityCurrentRail->transform->m_transform->ScalingUniforme(m_fScale);

        //Select the rail Prefab
        switch(m_currentDirection)
        {
            case (enumDirection::Forward) :
            {
                int fRandom = rand() % 3 + 1 ;
                m_nbPositionZ = m_nbPositionZ - m_Lenght;
                switch (fRandom)
                {
                    case (1): //Straight forward
                    {
                        CreateStraightRails(90, l_entityCurrentRail, l_meshComponentRailsForward);
                        m_currentDirection = enumDirection::Forward;
//                        Debug::s_inst->ScreenLog("Straight forward", 1000);
                       
                        break;
                    }
                    case (2): //Turn Right
                    {
                        l_meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Right.x");
                        l_entityCurrentRail->AddComponent(l_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 90, 0);
                        m_currentDirection = enumDirection::Right;
 //                       Debug::s_inst->ScreenLog("Turn Right", 1000);
                      
                        break;
                    }
                    case (3): //Turn Left
                    {
                        l_meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Right.x");
                        l_entityCurrentRail->AddComponent(l_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 180, 0);
                        m_currentDirection = enumDirection::Left;
//                        Debug::s_inst->ScreenLog("Turn Left",1000);
                        break;
                    }
                } 
         
            }
            case (enumDirection::Backward):
            {
                break;
            }
            case (enumDirection::Right):
            {

               // srand(Timer::s_inst->GetSystemTimeEx());
                int fRandom = rand() % 2 + 1 ;
                m_nbPositionX = m_nbPositionX - m_Lenght;
                switch (fRandom)
                {
                    case (1): //Straight Right
                    {
                        l_meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Forward.x");
                        l_entityCurrentRail->AddComponent(l_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 0, 0);
                        m_currentDirection = enumDirection::Right;
//                        Debug::s_inst->ScreenLog("Straight Right", 1000);
                       
                    }
                    case (2): //Turn Left
                    {
                        l_meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Right.x");
                        l_entityCurrentRail->AddComponent(l_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 270, 0);
                        m_currentDirection = enumDirection::Forward;
 //                       Debug::s_inst->ScreenLog("Turn Left", 1000);
                    }
                }
 
                break;
            }
            case (enumDirection::Left):
            {
                int fRandom = rand() % 2 + 1;
                m_nbPositionX = m_nbPositionX + m_Lenght;
                switch (fRandom)
                {
                    case (1): //Straight Left
                    {
  
                        l_meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Forward.x");
                        l_entityCurrentRail->AddComponent(l_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 0, 0);
                        m_currentDirection = enumDirection::Left;
//                        Debug::s_inst->ScreenLog("Straight Left", 1000);
                    }
                    case (2): //Turn Right
                    {
                        l_meshComponentRailsForward->SetMeshAndTexturePath("..\\Ressources\\Rail-Right.x");
                        l_entityCurrentRail->AddComponent(l_meshComponentRailsForward);
                        l_entityCurrentRail->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                        l_entityCurrentRail->transform->m_transform->RotateAngle(0, 0, 0);
                        m_currentDirection = enumDirection::Forward;
//                        Debug::s_inst->ScreenLog("Turn Right", 1000);
                    }
                }
                break;
            }
        }
        //Add to the list of rails
        m_listEntityRails.push_back(l_entityCurrentRail);
    }


}


void RailManager::RemoveRails()
{
    //To call after X sec to remove last rails from the list ans create one forward
}

void RailManager::CreateStraightRails(float fRotationAngleY, Entity* entity, MeshComponent* meshComponent)
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
                meshComponent->SetMeshAndTexturePath("..\\Ressources\\Rail-Up.x");
                entity->AddComponent(meshComponent);
                entity->transform->m_transform->SetPosition(m_nbPositionX, m_nbPositionY, m_nbPositionZ);
                entity->transform->m_transform->RotateAngle(0, fRotationAngleY, fRotationAngleZ);
                bRailHasBeenCreated = true;
                break;
            }
            case (2):
            {
                fRotationAngleZ += 0;
                meshComponent->SetMeshAndTexturePath("..\\Ressources\\Rail-Forward.x");
                entity->AddComponent(meshComponent);
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
                    fRotationAngleY += 0;
                    m_nbPositionY = m_nbPositionY - m_Height / 2;
                    meshComponent->SetMeshAndTexturePath("..\\Ressources\\Rail-Up.x");
                    entity->AddComponent(meshComponent);
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
