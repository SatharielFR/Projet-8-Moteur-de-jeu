#pragma once

class Entity;

class Component
{
	public:
		#pragma region PublicVariables
			int id;
			string name;
		#pragma endregion 

		#pragma region PublicFunctions
			virtual void Begin();
			virtual void Update();
			virtual void Render();
			void SetParent(Entity* newParentEntity);
		#pragma endregion 

	protected:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
		#pragma endregion
};