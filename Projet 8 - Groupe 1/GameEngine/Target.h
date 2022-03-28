#pragma once
#include "framework.h"

class Target
{
	public:

		#pragma region publicVariables
			Entity* l_target;
			Scene* m_scene;
			int life;
		#pragma endregion

		#pragma region PublicFunctions
			Target(Scene* scene);
			void Begin(Scene* scene);
			void CreateTarget(Scene* scene);
			void Destroy(Scene* scene);
		#pragma endregion
};

