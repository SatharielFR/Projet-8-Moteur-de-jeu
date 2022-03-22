#include "pch.h"
#include "framework.h"

int TransformComponent::s_type = 1;

TransformComponent::TransformComponent()
{
	m_transform = new Transform();
	TransformComponent::name = "Transform";
}

void TransformComponent::Begin()
{
	Component::Begin();
}

