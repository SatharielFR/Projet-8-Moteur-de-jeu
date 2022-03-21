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
list<MeshComponent*> SceneManager::GetMeshComponents()
{
	if (_currentScene)
	{
		//Check all entities
		for (Entity* currentEntity : _currentScene->GetEntities())
		{
			////Check if we got a Mesh Component
			//if (currentEntity->GetComponentByType<MeshComponent>() != nullptr)
			//{
			//	//Render It
			//	Debug::s_inst->ScreenLog("Render Mesh Component");
			//}
		}
	}
	return list<MeshComponent*>();
}
