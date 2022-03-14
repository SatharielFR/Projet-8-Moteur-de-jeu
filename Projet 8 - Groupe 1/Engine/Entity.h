#pragma once
//#include "framework.h"

class Entity
{
	public:
		#pragma region PublicVariables
			//transform
			//collider
			//mesh
		#pragma endregion 

		#pragma region PublicFunctions
			void Begin();
			void Update();

			void SetParent(Entity* newParentEntity);
			void AddChild(Entity* newChildToAdd);
			void RemoveChild(Entity* childToRem);
		#pragma endregion 

	private:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
			list<Entity*> _lstEntityChild;
		#pragma endregion
};

