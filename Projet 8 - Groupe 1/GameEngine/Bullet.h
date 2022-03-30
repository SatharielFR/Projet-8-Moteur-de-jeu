#pragma once
#include "framework.h"

class Bullet
{
	public:

		#pragma region publicVariables
			Entity* l_bullet;
			Scene* m_scene;
		#pragma endregion

		#pragma region PublicFunctions
			Bullet(Scene* scene);
			void Begin(Scene* scene);
			void CreateBullet(Scene* scene);
		#pragma endregion
};

