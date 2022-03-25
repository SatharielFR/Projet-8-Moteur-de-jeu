#pragma once
#include "framework.h"

#pragma region ForwardDeclaration
	class RailManager;
	class Entity;
#pragma endregion


class Cart
{
	public:
		Cart(Scene* scene, RailManager* railManager);
		~Cart();

		#pragma region Variables
			Scene* m_scene = nullptr;
			RailManager* m_railManager = nullptr;
			Entity* m_currentRailEntity = nullptr;
			std::list<Entity*>::iterator itRail;
			Entity* m_entityCart;
			D3DXVECTOR3 m_vec3CartPosition;
			float m_fCartSpeed = 1.f;
		#pragma endregion

		#pragma region Functions
			void Update();
			//void Lerp(D3DXVECTOR3 A, D3DXVECTOR3 B, float step);
		#pragma endregion

		#pragma region Accessor
	//		m_vec3CartPosition
			D3DXVECTOR3 GetCartPosition();
		#pragma endregion

	private:
#

};

