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

void SceneManager::Begin()
{
	if (_currentScene)
	{
		_currentScene->Begin();
	}
}

/// <summary>
/// Render the current Active scene
/// </summary>
list<MeshComponent*> SceneManager::GetMeshComponents()
{
	list<MeshComponent*> l_lstMeshComponents;
	if (_currentScene)
	{
		//Check all entities
		for (Entity* currentEntity : _currentScene->GetEntities())
		{
			//Check if we got a Mesh Component
			MeshComponent* l_currentMeshComponent = (MeshComponent*)(currentEntity->GetComponentByType<MeshComponent>());
			if (l_currentMeshComponent != nullptr)
			{
				//Render It
				l_lstMeshComponents.push_back(l_currentMeshComponent);
			}
		}
	}
	return l_lstMeshComponents;
}
