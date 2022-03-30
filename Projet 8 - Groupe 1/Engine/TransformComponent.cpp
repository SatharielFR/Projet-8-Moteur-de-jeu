#include "pch.h"
#include "framework.h"

int TransformComponent::s_type = 1;

TransformComponent::TransformComponent()
{
	
	m_transform = new Transform();
	TransformComponent::name = "Transform";
}

TransformComponent::~TransformComponent()
{
	//Debug::s_inst->ScreenLog("Transform");
	//ConsoleLog("Transform");
	delete m_transform;
}

void TransformComponent::Begin()
{
	Component::Begin();
}

