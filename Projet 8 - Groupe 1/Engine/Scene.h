#pragma once

//#include "framework.h"

class Entity;

class Scene
{
	public:
		void Begin();
		void Update();

	private:
		#pragma region PrivateVariables
			list<Entity*> _listEntity;
		#pragma endregion
};

