#include "pch.h"
#include "framework.h"

SceneManager::SceneManager()
{
}

void SceneManager::AddScene(Scene* sceneToAdd)
{
	_lstScenes.push_back(sceneToAdd);
}

void SceneManager::OpenScene(string strSceneName)
{
	for(Scene* currentScene : _lstScenes)
	{
		if (currentScene->GetSceneName() == strSceneName)
		{
			_currentScene = currentScene;
		}
	}
}

void SceneManager::UpdateScene()
{
	if (_currentScene)
	{
		_currentScene->Update();
	}
}
