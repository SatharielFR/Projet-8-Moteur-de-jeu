#include "Bullet.h"

Bullet::Bullet(Scene* scene)
{
	l_bullet = new Entity();
	Begin(scene);
}

Bullet::~Bullet()
{
	delete l_bullet;
	m_scene = nullptr;
	delete m_scene;
}

void Bullet::Begin(Scene* scene)
{
	CreateBullet(scene);
}

void Bullet::CreateBullet(Scene* scene)
{
	m_scene = scene;
	m_scene->AddEntity(l_bullet);
	MeshComponent* l_meshBullet = new MeshComponent();
	l_meshBullet->SetMeshAndTexturePath("Ressources\\Bullet.x");
	l_bullet->AddComponent(l_meshBullet);
	RigidbodyComponent* l_rigidbodyBullet = new RigidbodyComponent();
	l_bullet->AddComponent(l_rigidbodyBullet);
}