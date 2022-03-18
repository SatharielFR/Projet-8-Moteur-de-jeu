#include "pch.h"
#include "framework.h"

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

void Component::AddComponent(Component* newComponent)
{
	if (newComponent == nullptr) { return; }

	for (auto i = Engine::lstComponents.begin(); i != Engine::lstComponents.end(); i++)
	{
		if (*i != newComponent)
		{
			Engine::lstComponents.push_back(newComponent);
		}
		else
		{
			return;
		}
	}
}


