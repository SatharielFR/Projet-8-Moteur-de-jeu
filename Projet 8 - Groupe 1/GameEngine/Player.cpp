#include "Player.h"
#include "Bullet.h"

Player::Player(Scene* scene)
{
	l_player = new Entity();
    _fShootForce = 5;
    Reset();
	Begin(scene);
}

void Player::Reset()
{
    score = 0;
    cooldown = 1.0f;
    canShoot = true;
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
    l_player->transform->m_transform->ScalingUniforme(0.01f);
}

void Player::Shoot(Scene* scene)
{
    std::vector<Entity*> l_entities = scene->GetEntities();
    for (Entity* l_currentEntity : l_entities)
    {
        CameraComponent* l_cameraComponent = (CameraComponent*)l_currentEntity->GetComponentByType<CameraComponent>();
        if (l_cameraComponent != nullptr)
        {
            if (canShoot && cooldown <= 0.f)
            {
                Bullet* projectile = new Bullet(scene);
                projectile->l_bullet->transform->m_transform->SetPosition(l_cameraComponent->origin.x, l_cameraComponent->origin.y, l_cameraComponent->origin.z);
                projectile->l_bullet->transform->m_transform->ScalingUniforme(0.02f);
                projectile->l_bullet->transform->m_transform->Rotate(_fRotationX, _fRotationY,0);
                RigidbodyComponent* l_bulletRigidbody = (RigidbodyComponent*)(projectile->l_bullet->GetComponentByType<RigidbodyComponent>());
                l_bulletRigidbody->GravityStrengh = 0.03f;
                l_bulletRigidbody->useGravity = true;
                if (l_bulletRigidbody != nullptr)
                {
                    D3DXVECTOR3 force = l_cameraComponent->direction;
                    force *= _fShootForce;
                    l_bulletRigidbody->AddForce(force);
                }
                canShoot = false;
                cooldown = 1.0f;

                //Sound
                PlaySound(TEXT("..\\Ressources\\Shoot.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
        }
    }
}

void Player::SaveRotation(float fRotationX, float fRotationY)
{
    _fRotationX = fRotationX;
    _fRotationY = fRotationY;
}
