#pragma once
#include "framework.h"

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
			void AddEntity(Entity* newEntityToAdd);
			void RemoveEntity(Entity* EntityToRem);
			void AddComponent(Component* newComponentToAdd);
			void RemoveComponent(Component* ComponentToRem);
		#pragma endregion 

	private:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
			list<Entity*> _lstEntityChild;
			list<Component*> _lstComponenetChild;
		#pragma endregion
};

