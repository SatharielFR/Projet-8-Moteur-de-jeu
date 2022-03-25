#include "Bullet.h"

Bullet::Bullet()
{
	l_bullet = new Entity();
	Begin();
}

void Bullet::Begin()
{
	CreateBullet();
}

void Bullet::CreateBullet()
{
	MeshComponent* l_meshBullet = new MeshComponent();
	l_meshBullet->SetMeshAndTexturePath("..\\Ressources\\Tiger.x");
	l_bullet->AddComponent(l_meshBullet);
	RigidbodyComponent* l_rigidbodyBullet = new RigidbodyComponent();
	l_bullet->AddComponent(l_rigidbodyBullet);
}
