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
	if (Debug::s_inst)
	{
		Debug::s_inst->DebugLog("Scene::Update");
	}
	Println("Scene::Update");
}

void Scene::SetSceneName(string strNewSceneName)
{
	_strSceneName = strNewSceneName;
}