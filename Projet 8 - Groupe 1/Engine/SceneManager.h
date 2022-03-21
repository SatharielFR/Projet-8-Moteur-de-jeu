#pragma once

//#include "scene.h"
#include <list>

 class Scene;


class SceneManager
{
public :
	#pragma region PublicFunctions
		SceneManager();
		void AddScene(Scene* sceneToAdd);
		void OpenScene(string strSceneName);
		void UpdateScene();
		void RenderScene();
	#pragma endregion

private: 
	#pragma region PrivateVariables
		Scene* _currentScene;
		std::list<Scene*> _lstScenes;
	#pragma endregion

	#pragma region PrivateFunctions

	#pragma endregion
};

