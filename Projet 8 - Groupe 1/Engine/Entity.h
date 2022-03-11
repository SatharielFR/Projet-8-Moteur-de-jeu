#pragma once


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
		#pragma endregion 

	private:
		#pragma region PrivateVariable
			Entity* _entityParent = nullptr;
//			Entit
		#pragma endregion
};

