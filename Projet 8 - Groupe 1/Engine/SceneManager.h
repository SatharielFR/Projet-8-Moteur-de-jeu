#pragma once
#include <list>
#include "scene.h"

using namespace std;

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
		list<Scene*> _lstScenes;
	#pragma endregion

	#pragma region PrivateFunctions

	#pragma endregion
};

