#pragma once

class Entity;

class Component
{
	public:
		#pragma region PublicVariables
			string name;
		#pragma endregion 

		#pragma region PublicFunctions
			void SetParent(Entity* newParentEntity);
			void AddComponent(Component* newComponent);
		#pragma endregion 

	private:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
		#pragma endregion
};