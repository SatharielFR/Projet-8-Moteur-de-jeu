#include "TargetSpawner.h"

TargetSpawner::TargetSpawner(Scene* scene, RailManager* railManager)
{
    _scene = scene;
	_railManager = railManager;

    _fSpawnPercentChance = 20.0f;
    _meshComponentTarget = new MeshComponent();
    _meshComponentTarget->SetMeshAndTexturePath("..\\Ressources\\Target.x");
}

TargetSpawner::~TargetSpawner()
{
    _meshComponentTarget = nullptr;
    delete _meshComponentTarget;
}

void TargetSpawner::Reset()
{
    if (_lstTarget.size() > 0)
    {
        for (Target* currentTarget : _lstTarget)
        {
            _scene->DestroyEntity(currentTarget->l_target);
            delete currentTarget;
        }
        _lstTarget.clear();
    }
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
                Target* target = new Target(_scene, _meshComponentTarget);
                target->l_target->transform->m_transform->ScalingUniforme(0.01f);


                //Set Position
                float l_fOffsetY = 5.0f;
                D3DXVECTOR3 vec3TargetPosition = currentRailEntity->transform->m_transform->m_vPos;
                vec3TargetPosition.y += l_fOffsetY;
                target->l_target->transform->m_transform->SetPosition(vec3TargetPosition.x, vec3TargetPosition.y, vec3TargetPosition.z);

                //Set Rotation  
                target->l_target->transform->m_transform->RotateAngle(90.0f, 0.f, 0.f);
            }     
		}
	}
}

void TargetSpawner::Close()
{
}
