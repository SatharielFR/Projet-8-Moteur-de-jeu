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

/// <summary>
/// Render the current Active scene
/// </summary>
void SceneManager::RenderScene()
{
	if (_currentScene)
	{
		//Check all entities
		for (Entity* currentEntity : _currentScene->GetEntities())
		{
			Debug::s_inst->ScreenLog("RenderScene");

			//Check if we got a Mesh Component
			if (currentEntity->GetComponentByName("truc") != nullptr)
			{
				//Render It
				//Getcompenent<Collider>()

			}
		}
	}
}
