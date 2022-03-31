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
			Scene* m_scene;
			RailManager* m_railManager;
			Entity* m_currentRailEntity;
			std::list<Entity*>::iterator itRail;
			Entity* m_entityCart;
			D3DXVECTOR3 m_vec3CartPosition;
		#pragma endregion

		#pragma region Functions
			void SetForwardValue(int value);
			void Update();
			void Reset();
		#pragma endregion

		#pragma region Accessor
			D3DXVECTOR3 GetCartPosition();
			bool GetHasReachEnd() { return _bHasReachEnd; }
		#pragma endregion

	private:
		#pragma region PrivateVariables
			bool _bHasReachEnd = false;
			int _nbForwardValue;
			float _fCartBoostSpeed;
			float _fCartDefaultSpeed;
			float _fCartSpeed;
			float _fLerpValue;
			D3DXVECTOR3* _vec3LerpStart;
			D3DXVECTOR3* _vec3LerpEnd;
			D3DXVECTOR3* _vec3NewLocation;
			D3DXQUATERNION* _quatLerpStart;
			D3DXQUATERNION* _quatLerpEnd;
			D3DXQUATERNION* _quatnewRotation;
		#pragma endregion

		#pragma region Utility
			void UpdateSpeed();
		#pragma endregion
};

