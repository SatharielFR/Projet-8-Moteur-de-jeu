#pragma once

//#include "scene.h"
#include <list>

 class Scene;


class SceneManager
{
public :
	#pragma region PublicFunctions
		SceneManager();
		void OpenScene();
		void UpdateScene();
	#pragma endregion

private: 
	#pragma region PrivateVariables
		Scene* _currentScene;
		std::list<Scene*> _lstScenes;
	#pragma endregion

	#pragma region PrivateFunctions

	#pragma endregion
};

