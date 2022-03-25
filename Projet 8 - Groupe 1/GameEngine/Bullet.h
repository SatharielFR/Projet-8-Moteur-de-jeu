#pragma once
#include "framework.h"

class Bullet
{
	public:

		#pragma region publicVariables
			Entity* l_bullet;
		#pragma endregion

		#pragma region PublicFunctions
			Bullet();
			void Begin();
			void CreateBullet();
		#pragma endregion
};

