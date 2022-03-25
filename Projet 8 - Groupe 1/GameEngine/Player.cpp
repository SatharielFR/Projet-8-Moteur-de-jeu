#include "Player.h"
#include "Bullet.h"

Player::Player()
{
	l_player = new Entity();
	canShoot = true;
	cooldown = 1.0f;
	Begin();
}

void Player::Begin()
{
	CreatePlayer();
}

void Player::Update()
{ 
    cooldown -= Timer::s_inst->GetDeltaTime();
    if (cooldown <= 0.f)
    {
        canShoot = true;
    }
}


void Player::CreatePlayer()
{
	CameraComponent* l_playerCamera = new CameraComponent();
	l_player->AddComponent(l_playerCamera);
	MeshComponent* l_meshPlayer = new MeshComponent();
	l_meshPlayer->SetMeshAndTexturePath("..\\Ressources\\Tiger.x");
	l_player->AddComponent(l_meshPlayer);
}

void Player::Shoot()
{
	if (canShoot && cooldown <= 0.f)
	{
        // Get screen point
        POINT point;
        if (GetCursorPos(&point))
        {
            int iMouseX = point.x;
            int iMouseY = point.y;

            // Calculate the picking ray
            Raycast ray = ray.CalcPickingRay(iMouseX, iMouseY);

            // transform the ray from view space to world space
            // get view matrix
            D3DXMATRIX view;
            Engine::d3ddev->GetTransform(D3DTS_VIEW, &view);

            // inverse it
            D3DXMATRIX viewInverse;
            D3DXMatrixInverse(&viewInverse, 0, &view);

            // apply on the ray
            ray.TransformRay(&ray, &viewInverse);

            Bullet* projectile = new Bullet();
            projectile->l_bullet->transform->m_transform->SetPosition(ray.direction.x, ray.direction.y, ray.direction.z);
        }

        canShoot = false;
        cooldown = 1.0f;
	}
}
