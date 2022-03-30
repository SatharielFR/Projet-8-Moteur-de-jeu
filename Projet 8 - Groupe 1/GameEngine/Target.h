#pragma once
#include "framework.h"
#include "Player.h"

class Target
{
	public:

		#pragma region publicVariables
			Entity* l_target;
			Scene* m_scene;
		#pragma endregion

		#pragma region PublicFunctions
			Target(Scene* scene);
			void Begin(Scene* scene);
			void CreateTarget(Scene* scene);
		#pragma endregion
};

