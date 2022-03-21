#include "pch.h"
#include "framework.h"



Scene::Scene(string strSceneName)
{
	SetSceneName(strSceneName);
}

void Scene::Begin()
{
}

void Scene::Update()
{
	for (Entity* currentEntity : _listEntity)
	{
		currentEntity->Update();
	}
}

void Scene::SetSceneName(string strNewSceneName)
{
	_strSceneName = strNewSceneName;
}

void Scene::AddEntity(Entity* l_entityToAdd)
{
	if (l_entityToAdd == nullptr) { return; }

	if (_listEntity.size() == 0 ) 
	{
		_listEntity.push_back(l_entityToAdd);
	}
	else
	{
		for (auto i = _listEntity.begin(); i != _listEntity.end(); i++)
		{
			if (*i != l_entityToAdd)
			{
				_listEntity.push_back(l_entityToAdd);
			}
			else
			{
				return;
			}
		}
	}
}