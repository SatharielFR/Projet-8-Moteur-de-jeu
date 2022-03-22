#pragma once

class Entity;

class Component
{
	public:
		#pragma region PublicVariables
			static int s_type;
			static string name;
		#pragma endregion 

		#pragma region PublicFunctions
			virtual void Begin();
			virtual void Update();
			virtual void Render();
			virtual int GetType() { return s_type; }
			void SetParent(Entity* newParentEntity);
		#pragma endregion 

	protected:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
		#pragma endregion
};