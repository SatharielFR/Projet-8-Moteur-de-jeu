#include "pch.h"
#include "framework.h"



Scene::Scene(string strSceneName)
{
	SetSceneName(strSceneName);
}

void Scene::Begin()
{
	for (Entity* currentEntity : _listEntity)
	{
		currentEntity->Begin();
	}
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
		return;
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
}

void Scene::AddHUD(HUD* l_HUDToAdd) {
	if (l_HUDToAdd == nullptr) { return; }

	if (_listHUD.size() == 0) {
		_listHUD.push_back(l_HUDToAdd);
		return;
	}
	else {
		bool l_bIsInTheList = false;
		for (auto i = _listHUD.begin(); i != _listHUD.end(); i++) {
			if (*i == l_HUDToAdd) {
				l_bIsInTheList = true;
			}
		}
		if (!l_bIsInTheList) {
			_listHUD.push_back(l_HUDToAdd);
		}
	}
}