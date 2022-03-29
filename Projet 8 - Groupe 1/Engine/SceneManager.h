#pragma once

//#include "scene.h"
#include <list>

 class Scene;
 class MeshComponent;

class SceneManager
{
public :
	#pragma region PublicFunctions
		SceneManager();
		void AddScene(Scene* sceneToAdd);
		void OpenScene(string strSceneName);
		void UpdateScene();
		void Begin();
	#pragma endregion

	#pragma region Accessors
		Scene* GetSceneByName(string strSceneName);
		Scene* GetCurrentScene() { return _currentScene;}
		list<MeshComponent*> GetMeshComponents();
	#pragma endregion

private: 
	#pragma region PrivateVariables
		Scene* _currentScene;
		std::list<Scene*> _lstScenes;
	#pragma endregion

	#pragma region PrivateFunctions

	#pragma endregion
};

