#pragma once

//#include "framework.h"

class Entity;

class Scene
{
	public:
		#pragma region PublicFunctions
			Scene(string strSceneName);
			void Begin();
			void Update();
		#pragma endregion

		#pragma region Accessors
			void SetSceneName(string strNewSceneName);
			string GetSceneName() { return _strSceneName;}
		#pragma endregion

	private:
		#pragma region PrivateVariables
			string _strSceneName = "Default";
			list<Entity*> _listEntity;
		#pragma endregion
};

