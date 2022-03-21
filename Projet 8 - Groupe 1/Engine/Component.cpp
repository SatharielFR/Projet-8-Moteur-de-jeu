#include "pch.h"
#include "framework.h"

int Component::id = 0;

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


