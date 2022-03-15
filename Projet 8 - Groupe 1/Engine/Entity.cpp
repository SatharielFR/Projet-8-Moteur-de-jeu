#include "pch.h"
#include "framework.h"

void Entity::Begin()
{

}

void Entity::Update()
{

}

void Entity::SetParent(Entity* newParentEntity)
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

void Entity::AddEntity(Entity* newEntityToAdd)
{
	if (newEntityToAdd == nullptr) { return; }

	for (auto i = _lstEntityChild.begin(); i != _lstEntityChild.end(); i++)
	{
		if (*i != newEntityToAdd)
		{
			_lstEntityChild.push_back(newEntityToAdd);
		}
		else
		{
			return;
		}
	}
}

void Entity::RemoveEntity(Entity* EntityToRem)
{
	if (EntityToRem == nullptr) { return; }

	for (auto i = _lstEntityChild.begin(); i != _lstEntityChild.end(); i++)
	{
		if (*i == EntityToRem)
		{
			_lstEntityChild.erase(i);
		}
	}
}

void Entity::AddComponent(Component* newComponentToAdd)
{
	if (newComponentToAdd == nullptr) { return; }

	for (auto i = _lstComponenetChild.begin(); i != _lstComponenetChild.end(); i++)
	{
		if (*i != newComponentToAdd)
		{
			_lstComponenetChild.push_back(newComponentToAdd);
		}
		else
		{
			return;
		}
	}
}

void Entity::RemoveComponent(Component* ComponentToRem)
{
	if (ComponentToRem == nullptr) { return; }

	for (auto i = _lstComponenetChild.begin(); i != _lstComponenetChild.end(); i++)
	{
		if (*i == ComponentToRem)
		{
			_lstComponenetChild.erase(i);
		}
	}
}
