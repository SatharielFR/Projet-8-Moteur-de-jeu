#include "pch.h"
#include "Entity.h"

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

void Entity::AddChild(Entity* newChildToAdd)
{
	if (newChildToAdd == nullptr) { return; }

	for (auto i = _lstEntityChild.begin(); i != _lstEntityChild.end(); i++)
	{
		if (*i != newChildToAdd)
		{
			_lstEntityChild.push_back(newChildToAdd);
		}
		else
		{
			return;
		}
	}
}

void Entity::RemoveChild(Entity* childToRem)
{
	if (childToRem == nullptr) { return; }

	for (auto i = _lstEntityChild.begin(); i != _lstEntityChild.end(); i++)
	{
		if(*i == childToRem)
		{
			_lstEntityChild.erase(i);
		}
	}
}