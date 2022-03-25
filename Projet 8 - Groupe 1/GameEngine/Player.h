#pragma once
#include "framework.h"

class Player
{
	public :

		#pragma region publicVariables
			Entity* l_player;
			bool canShoot;
			float cooldown;
		#pragma endregion

		#pragma region PublicFunctions
			Player();
			void Begin();
			void Update();
			void CreatePlayer();
			void Shoot();
		#pragma endregion
};

