#include "pch.h"
#include "framework.h"

int RigidbodyComponent::s_type = 4;

RigidbodyComponent::RigidbodyComponent()
{
	Begin();
}

void RigidbodyComponent::Begin()
{
	velocity = { 0.0, 0.0, 0.0 };
	useGravity = false;
	GravityStrengh = 1.f;
	radius = 1;
}

void RigidbodyComponent::Update()
{
	if (useGravity == true)
	{
		velocity.y -= Engine::gravity * GravityStrengh * Timer::s_inst->GetDeltaTime();
		_entityParent->transform->m_transform->Move(velocity.x, velocity.y, velocity.z);
	}
}

void RigidbodyComponent::AddForce(D3DXVECTOR3 force)
{
	velocity += force;
}
