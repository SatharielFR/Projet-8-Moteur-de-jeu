#include "pch.h"
#include "framework.h"

TransformComponent::TransformComponent()
{
	TransformComponent::name = "Transform";
	TransformComponent::AddComponent(this);
}

