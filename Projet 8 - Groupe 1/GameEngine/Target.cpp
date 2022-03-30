#include "Target.h"

Target::Target(Scene* scene)
{
	l_target = new Entity();
	Begin(scene);
}

void Target::Begin(Scene* scene)
{
	CreateTarget(scene);
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

