#include "TargetSpawner.h"

TargetSpawner::TargetSpawner(Scene* scene, RailManager* railManager)
{
    _scene = scene;
	_railManager = railManager;

    _fSpawnPercentChance = 20.0f;
}

TargetSpawner::~TargetSpawner()
{
}

void TargetSpawner::Init()
{
}

void TargetSpawner::SpawnTargets()
{
	if (_railManager)
	{
		for (Entity* currentRailEntity : _railManager->m_listEntityRails)
		{
            //Check the percent chance
            float fRandom = rand() % 100;
            if (fRandom > 100 - _fSpawnPercentChance)
            {
                //Create a Target
                Entity* l_entityTarget = new Entity();
                _scene->AddEntity(l_entityTarget);
                MeshComponent* l_meshComponentTarget = new MeshComponent();
                l_meshComponentTarget->SetMeshAndTexturePath("..\\Ressources\\Target.x");
                l_entityTarget->AddComponent(l_meshComponentTarget);
                RigidbodyComponent* l_rigidbodyTarget = new RigidbodyComponent();
                l_rigidbodyTarget->radius = 5;
                l_entityTarget->AddComponent(l_rigidbodyTarget);
                l_entityTarget->transform->m_transform->ScalingUniforme(0.01f);


                //Set Position
                float l_fOffsetY = 5.0f;
                D3DXVECTOR3 vec3TargetPosition = currentRailEntity->transform->m_transform->m_vPos;
                vec3TargetPosition.y += l_fOffsetY;
                l_entityTarget->transform->m_transform->SetPosition(vec3TargetPosition.x, vec3TargetPosition.y, vec3TargetPosition.z);

                //Set Rotation  
                l_entityTarget->transform->m_transform->RotateAngle(90.0f, 0.f, 0.f);
            }     
		}
	}
}

void TargetSpawner::Close()
{
}
