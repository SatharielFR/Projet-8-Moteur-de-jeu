#include "pch.h"
#include "framework.h"

void Entity::Begin()
{
	transform = new TransformComponent;
	AddComponent(transform);
}

void Entity::Update()
{
	//Update All child Entities
	for (Entity* currentEntity : _lstEntityChild)
	{
		currentEntity->Update();
	}
	//Update All Components
	for (Component* currentChild : _lstComponentChild)
	{
		currentChild->Update();
	}
}

void Entity::Render()
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

	if (_lstEntityChild.size() == 0)
	{
		_lstEntityChild.push_back(newEntityToAdd);
	}
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

	if (_lstComponentChild.size() == 0)
	{
		_lstComponentChild.push_back(newComponentToAdd);
	}
	for (auto i = _lstComponentChild.begin(); i != _lstComponentChild.end(); i++)
	{
		if (*i != newComponentToAdd)
		{
			newComponentToAdd->SetParent(this);
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
	return nullptr;
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
