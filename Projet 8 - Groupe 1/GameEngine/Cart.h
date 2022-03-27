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
		#pragma region PrivateVariables
			float _fCartSpeed = 1.5f;
			float _fLerpValue = 0;
			D3DXVECTOR3* _vec3LerpStart;
			D3DXVECTOR3* _vec3LerpEnd;
			D3DXVECTOR3* l_newLocation;
		#pragma endregion

		#pragma region Utility
//			D3DXVECTOR3 Lerp(D3DXVECTOR3 a, D3DXVECTOR3 b, float s);
		#pragma endregion
};

