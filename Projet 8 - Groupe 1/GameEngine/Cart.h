#pragma once
#include "framework.h"

class Cart
{
	public:
		Cart(Scene* scene);
		~Cart();

		#pragma region Variables
			Scene* m_scene = nullptr;
			Entity* m_entityCart;
			D3DXVECTOR3 m_vec3CartPosition;
		#pragma endregion

		#pragma region Functions
			//void MoveCart();
			//void Lerp(D3DXVECTOR3 A, D3DXVECTOR3 B, float step);
		#pragma endregion

		#pragma region Accessor
	//		m_vec3CartPosition
		#pragma endregion

	private:
#

};

