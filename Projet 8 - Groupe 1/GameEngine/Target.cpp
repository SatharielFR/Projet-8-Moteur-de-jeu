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

void Target::CreateTarget(Scene* scene)
{
	m_scene = scene;
	m_scene->AddEntity(l_target);
	MeshComponent* l_meshBullet = new MeshComponent();
	l_meshBullet->SetMeshAndTexturePath("..\\Ressources\\Target.x");
	l_target->AddComponent(l_meshBullet);
}

void Target::Destroy(Scene* scene)
{
	scene->DestroyEntity(l_target);

}
