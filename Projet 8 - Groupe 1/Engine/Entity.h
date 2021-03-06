#pragma once

class TransformComponent;
class Component;

class Entity
{
	public:
		#pragma region PublicVariables
			Entity();
			~Entity();
			TransformComponent* transform;
			//collider
			//mesh
		#pragma endregion 

		#pragma region PublicFunctions
			void Begin();
			virtual void Update();
			virtual void Render();
			void SetParent(Entity* newParentEntity);
			void AddEntity(Entity* newEntityToAdd);
			void RemoveEntity(Entity* EntityToRem);
			void AddComponent(Component* newComponentToAdd);
			Component* GetComponentByName(string name);

			template<typename T>
			Component* GetComponentByType();

			void RemoveComponent(Component* ComponentToRem);
		#pragma endregion 

	protected:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
			vector<Entity*> _lstEntityChild;
			vector<Component*> _lstComponentChild;
		#pragma endregion
};

template<typename T>
inline Component* Entity::GetComponentByType()
{
	if (_lstComponentChild.size()>0)
	{
		for (Component* comp : _lstComponentChild)
		{
			if (comp != nullptr) 
			{
				if (comp->GetType() == T::s_type)
				{
					return comp;
				}
			}
		}
	}
	return nullptr;
}
