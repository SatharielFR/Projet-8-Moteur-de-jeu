#include "pch.h"
#include "framework.h"

SceneManager::SceneManager()
{
}

void SceneManager::AddScene(Scene* sceneToAdd)
{
	_lstScenes.push_back(sceneToAdd);
//	advance(_lstScenes, 0)->GetName();
}

void SceneManager::OpenScene(string strSceneName)
{
//	_currentScene = strSceneName;

	//for each (Scene* currentScene in _lstScenes)
	//{

	//}
}

void SceneManager::UpdateScene()
{
	if (_currentScene)
	{
		_currentScene->Update();
	}
}
