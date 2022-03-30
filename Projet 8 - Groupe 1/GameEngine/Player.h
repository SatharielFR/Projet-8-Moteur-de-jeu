#pragma once
#include "framework.h"

class Player
{
	public :

		#pragma region publicVariables
			Entity* l_player;
			Scene* m_scene;
			bool canShoot;
			float cooldown;
			int score;
		#pragma endregion

		#pragma region PublicFunctions
			Player(Scene* scene);
			void Reset();
			void Begin(Scene* scene);
			void Update(Scene* scene);
			void CreatePlayer(Scene* scene);
			void Shoot(Scene* scene);
		#pragma endregion
};

