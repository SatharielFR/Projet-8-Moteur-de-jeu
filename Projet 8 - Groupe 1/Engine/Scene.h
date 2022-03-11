#pragma once
#include <list>
#include "Entity.h"

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

