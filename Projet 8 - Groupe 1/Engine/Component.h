#pragma once

class Entity;

class Component
{
	public:
		#pragma region PublicVariables
			string name;
		#pragma endregion 

		#pragma region PublicFunctions
			virtual void Begin();
			virtual void Update();
			virtual void Render();
			void SetParent(Entity* newParentEntity);
//			void AddComponent(Component* newComponent);
		#pragma endregion 

	protected:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
		#pragma endregion
};