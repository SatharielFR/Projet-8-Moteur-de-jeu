#include "pch.h"
#include "framework.h"



Scene::Scene(string strSceneName)
{
	SetSceneName(strSceneName);
}

Scene::~Scene()
{
	ConsoleLog("Scene");
}

void Scene::Begin()
{
	for (Entity* currentEntity : _listEntity)
	{
		currentEntity->Begin();
		//initialize the hud _sceneHUD->InitializeHUD(device);
	}
}

void Scene::Update()
{
	for (Entity* currentEntity : _listEntity)
	{
		currentEntity->Update();
		//_sceneHUD->UpdateHUD(device); update the hud
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
		bool l_bIsInTheList = false;
		for (auto i = _listEntity.begin(); i != _listEntity.end(); i++)
		{
			if (*i == l_entityToAdd)
			{
				l_bIsInTheList = true;
			}
		}
		if (!l_bIsInTheList)
		{
			_listEntity.push_back(l_entityToAdd);
		}
	}
	SetEntityHasBeenHaded(true);
}

void Scene::DestroyEntity(Entity* l_entityToDestroy)
{
	if (l_entityToDestroy == nullptr || _listEntity.size() < 1) { return; }

	auto i = std::find(_listEntity.begin(), _listEntity.end(), l_entityToDestroy);

	if (i == _listEntity.end()) { return;  }

	_listEntity.erase(i);
	delete l_entityToDestroy;
}

void Scene::AddHUD(HUD* HUDToAdd) {
	_sceneHUD = HUDToAdd;
}

