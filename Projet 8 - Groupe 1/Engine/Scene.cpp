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

}

void Scene::SetSceneName(string strNewSceneName)
{
	_strSceneName = strNewSceneName;
}