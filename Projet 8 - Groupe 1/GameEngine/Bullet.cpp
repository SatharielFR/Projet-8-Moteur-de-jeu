#include "Bullet.h"

Bullet::Bullet(Scene* scene)
{
	l_bullet = new Entity();
	damage = 1;
	lifetime = 3.f;
	Begin(scene);
}

void Bullet::Begin(Scene* scene)
{
	CreateBullet(scene);
}

void Bullet::Update(Scene* scene)
{
	lifetime -= Timer::s_inst->GetDeltaTime();
	Debug::s_inst->ScreenLog(lifetime);
	if (lifetime <= 0.f)
	{
		Destroy(scene);
	}
}

void Bullet::CreateBullet(Scene* scene)
{
	m_scene = scene;
	m_scene->AddEntity(l_bullet);
	MeshComponent* l_meshBullet = new MeshComponent();
	l_meshBullet->SetMeshAndTexturePath("..\\Ressources\\Cube.x");
	l_bullet->AddComponent(l_meshBullet);
	RigidbodyComponent* l_rigidbodyBullet = new RigidbodyComponent();
	l_bullet->AddComponent(l_rigidbodyBullet);
}

void Bullet::Destroy(Scene* scene)
{
	scene->DestroyEntity(l_bullet);
}