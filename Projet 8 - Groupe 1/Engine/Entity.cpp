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
	//Only add Entity
	if (newEntityToAdd == nullptr) { return; }
	//If the list is empty, just add it
	if (_lstEntityChild.size() == 0)
	{
		_lstEntityChild.push_back(newEntityToAdd);
		return;
	}
	//Only Add o the list if its not already in
	bool l_bIsInTheList = false;
	for (auto i = _lstEntityChild.begin(); i != _lstEntityChild.end(); i++)
	{
		if (*i == newEntityToAdd)
		{
			l_bIsInTheList = true;
		}
	}
	if (!l_bIsInTheList)
	{
		_lstEntityChild.push_back(newEntityToAdd);
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
	//Only add Componnent
	if (newComponentToAdd == nullptr) { return; }
	//If the list is empty, just add it
	if (_lstComponentChild.size() == 0)
	{
		_lstComponentChild.push_back(newComponentToAdd);
		return;
	}
	//Only Add o the list if its not already in
	bool l_bIsInTheList = false;
	for (auto i = _lstComponentChild.begin(); i != _lstComponentChild.end(); i++)
	{
		if (*i == newComponentToAdd)
		{
			l_bIsInTheList = true;
		}
	}
	if (!l_bIsInTheList)
	{
		_lstComponentChild.push_back(newComponentToAdd);
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
