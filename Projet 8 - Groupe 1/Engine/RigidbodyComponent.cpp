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
	useGravity = true;
	GravityStrengh = 1.f;
}

void RigidbodyComponent::Update()
{
	velocity.y -= Engine::gravity * GravityStrengh * Timer::s_inst->GetDeltaTime();
	_entityParent->transform->m_transform->Move(velocity.x, velocity.y, velocity.z);
}

void RigidbodyComponent::AddForce(D3DXVECTOR3 force)
{
	velocity += force;
}
