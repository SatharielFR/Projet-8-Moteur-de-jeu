#include "Player.h"
#include "Bullet.h"

Player::Player(Scene* scene)
{
	l_player = new Entity();
	canShoot = true;
	cooldown = 1.0f;
	Begin(scene);
}

void Player::Begin(Scene* scene)
{
	CreatePlayer(scene);
}

void Player::Update(Scene* scene)
{ 
    cooldown -= Timer::s_inst->GetDeltaTime();
    if (cooldown <= 0.f)
    {
        canShoot = true;
    }
    if (GetKeyState(VK_LBUTTON) & 0x8000)
    {

        Shoot(scene);
    }
}


void Player::CreatePlayer(Scene* scene)
{
    m_scene = scene;
    m_scene->AddEntity(l_player);
    l_player->transform->m_transform->SetPosition(0.0f, 0.0f, 0.0f);
    l_player->transform->m_transform->ScalingUniforme(0.01f);
}

void Player::Shoot(Scene* scene)
{
    list<Entity*> l_entities = scene->GetEntities();
    for (Entity* l_currentEntity : l_entities)
    {
        CameraComponent* l_cameraComponent = (CameraComponent*)l_currentEntity->GetComponentByType<CameraComponent>();
        if (l_cameraComponent != nullptr)
        {
            if (canShoot && cooldown <= 0.f)
            {
                Bullet* projectile = new Bullet(scene);
                projectile->l_bullet->transform->m_transform->SetPosition(l_cameraComponent->origin.x, l_cameraComponent->origin.y, l_cameraComponent->origin.z);
                projectile->l_bullet->transform->m_transform->ScalingUniforme(0.01f);
                RigidbodyComponent* l_bulletRigidbody = (RigidbodyComponent*)(projectile->l_bullet->GetComponentByType<RigidbodyComponent>());
                if (l_bulletRigidbody != nullptr)
                {
                    D3DXVECTOR3 force = l_cameraComponent->direction;
                    force *= 10.0f;
                    l_bulletRigidbody->AddForce(force);
                }

                canShoot = false;
                cooldown = 1.0f;
            }
        }
    }
}
