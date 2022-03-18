#include "pch.h"
#include "framework.h"

void Entity::Begin()
{
	transform = new TransformComponent;
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

	for (auto i = _lstComponentChild.begin(); i != _lstComponentChild.end(); i++)
	{
		if (*i != newComponentToAdd)
		{
			_lstComponentChild.push_back(newComponentToAdd);
		}
		else
		{
			return;
		}
	}
}

Component* Entity::GetComponentByName(string name)
{
	for (Component* comp : _lstComponentChild)
	{
		if (comp->name == name)
		{
			return comp;
		}
	}
}

void Entity::RemoveComponent(Component* ComponentToRem)
{
	if (ComponentToRem == nullptr) { return; }

	for (auto i = _lstComponentChild.begin(); i != _lstComponentChild.end(); i++)
	{
		if (*i == ComponentToRem)
		{
			_lstComponentChild.erase(i);
		}
	}
}
