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
			void SaveRotation(float fRotationX, float fRotationY);
		#pragma endregion

	private:
		#pragma region PrivateVariables
			float _fRotationX;
			float _fRotationY;
			float _fShootForce;
		#pragma endregion
};

