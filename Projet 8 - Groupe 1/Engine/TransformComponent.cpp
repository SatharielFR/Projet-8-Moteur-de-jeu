#include "pch.h"
#include "framework.h"

TransformComponent::TransformComponent()
{
	m_transform = new Transform();
	TransformComponent::id = 1;
	TransformComponent::name = "Transform";
}

void TransformComponent::Begin()
{
	Component::Begin();
	//m_transform = new Transform();
	//m_transform->Begin();
}

