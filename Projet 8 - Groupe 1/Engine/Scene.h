#pragma once

#pragma region ForwardDeclaration
	class Entity;
	class HUD;
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
			void AddHUD(HUD* l_HUDToAdd);
			void SetSceneName(string strNewSceneName);
			string GetSceneName() { return _strSceneName;}
			list<Entity*> GetEntities() { return _listEntity; }
			list<HUD*> GetHUDList() { return _listHUD; }
		#pragma endregion

	private:
		#pragma region PrivateVariables
			string _strSceneName = "Default";
			list<Entity*> _listEntity;
			list<HUD*> _listHUD;
		#pragma endregion
};

