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
			Target(Scene* scene, MeshComponent* meshComponent);
			void CreateTarget(Scene* scene, MeshComponent* meshComponent);
		#pragma endregion
};

