#pragma once

#pragma region ForwardDeclaration
	class Entity;
#pragma endregion

class Scene
{
	public:
		#pragma region PublicFunctions
			Scene(string strSceneName);
			void Begin();
			void Update();
		#pragma endregion

		#pragma region Accessors
			void AddEntity(Entity* l_entityToAdd);
			void SetSceneName(string strNewSceneName);
			string GetSceneName() { return _strSceneName;}
			list<Entity*> GetEntities() { return _listEntity; }
		#pragma endregion

	private:
		#pragma region PrivateVariables
			string _strSceneName = "Default";
			list<Entity*> _listEntity;
		#pragma endregion
};

