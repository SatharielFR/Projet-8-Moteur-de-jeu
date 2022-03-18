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
	//if (Debug::s_inst)
	//{
	//	Debug::s_inst->ScreenLog("Scene::Update");
	//}
	//ConsoleLog("Scene::Update");

	//testing mesh class



	//Print Time to screen
	string* l_strCurrentTime = new string("Time since start : " + std::to_string(Timer::s_inst->GetSystemTimeEx()) + "s");
	if (Debug::s_inst)
	{
		Debug::s_inst->ScreenLog(l_strCurrentTime);
	}
}

void Scene::SetSceneName(string strNewSceneName)
{
	_strSceneName = strNewSceneName;
}