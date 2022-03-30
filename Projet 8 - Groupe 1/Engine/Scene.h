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
			void DestroyEntity(Entity* l_entityToDestroy);
			void AddHUD(HUD* l_HUDToAdd);
			void SetSceneName(string strNewSceneName);
			string GetSceneName() { return _strSceneName;}
			std::vector<Entity*> GetEntities() { return _listEntity; }
			HUD* GetHUD() { return _sceneHUD; }
			void SetIsRunning(bool value) {m_bIsRunning = value;}
			bool GetIsRunning() {return m_bIsRunning;}
		#pragma endregion

	private:
		#pragma region PrivateVariables
			string _strSceneName = "Default";
			std::vector<Entity*> _listEntity;
			HUD* _sceneHUD;
			bool m_bIsRunning = false;
		#pragma endregion
};

