#include "Target.h"

Target::Target(Scene* scene, MeshComponent* meshComponent)
{
	l_target = new Entity();
	CreateTarget(scene, meshComponent);
}


void Target::CreateTarget(Scene* scene, MeshComponent* meshComponent)
{
	m_scene = scene;
	m_scene->AddEntity(l_target);
	l_target->AddComponent(meshComponent);
	RigidbodyComponent* l_rigidbodyTarget = new RigidbodyComponent();
	l_rigidbodyTarget->useGravity = false;
	l_rigidbodyTarget->radius = 4;
	l_target->AddComponent(l_rigidbodyTarget);
}

