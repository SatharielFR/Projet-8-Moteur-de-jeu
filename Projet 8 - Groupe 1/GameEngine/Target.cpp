#include "Target.h"

Target::Target(Scene* scene)
{
	l_target = new Entity();
	life = 1;
	Begin(scene);
}

void Target::Begin(Scene* scene)
{
	CreateTarget(scene);
}

void Target::Update(Scene* scene, Player* player)
{
	if (life == 0)
	{
		Destroy(scene, player);
	}
}

void Target::CreateTarget(Scene* scene)
{
	m_scene = scene;
	m_scene->AddEntity(l_target);
	MeshComponent* l_meshTarget = new MeshComponent();
	l_meshTarget->SetMeshAndTexturePath("..\\Ressources\\Target.x");
	l_target->AddComponent(l_meshTarget);
	RigidbodyComponent* l_rigidbodyTarget = new RigidbodyComponent();
	l_rigidbodyTarget->useGravity = false;
	l_rigidbodyTarget->radius = 5;
	l_target->AddComponent(l_rigidbodyTarget);
}

void Target::Destroy(Scene* scene, Player* player)
{
	scene->DestroyEntity(l_target);
	player->score += 1;
}
