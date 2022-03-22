#include "pch.h"
#include "framework.h"

int TransformComponent::_type = 1;

TransformComponent::TransformComponent()
{
	m_transform = new Transform();
	TransformComponent::name = "Transform";
}

void TransformComponent::Begin()
{
	Component::Begin();
	//m_transform = new Transform();
	//m_transform->Begin();
}

