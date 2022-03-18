#pragma once

class TransformComponent;

class Entity
{
	public:
		#pragma region PublicVariables
			TransformComponent* transform;
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
			Component* GetComponentByName(string name);
			void RemoveComponent(Component* ComponentToRem);
		#pragma endregion 

	private:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
			list<Entity*> _lstEntityChild;
			vector<Component*> _lstComponentChild;
		#pragma endregion
};

