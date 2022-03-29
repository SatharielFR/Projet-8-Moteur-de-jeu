#pragma once
#include "framework.h"

class Bullet
{
	public:

		#pragma region publicVariables
			Entity* l_bullet;
			Scene* m_scene;
			int damage;
			float lifetime;
		#pragma endregion

		#pragma region PublicFunctions
			Bullet(Scene* scene);
			void Begin(Scene* scene);
			void Update(Scene* scene);
			void CreateBullet(Scene* scene);
			void Destroy(Scene* scene);
		#pragma endregion
};

