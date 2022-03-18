#include "pch.h"
#include "framework.h"

void Component::Begin()
{
	//nothing
}

void Component::Update()
{
	//nothing
}

void Component::Render()
{
	//nothing
}

void Component::SetParent(Entity* newParentEntity)
{
	if (_entityParent != nullptr)
	{
		return;
	}
	else
	{
		_entityParent = newParentEntity;
	}
}


