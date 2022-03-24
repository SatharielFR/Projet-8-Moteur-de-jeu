#pragma once
#include <list>
#include "framework.h"

//class Entity;
//class Scene;


class RailManager
{
	public :
		#pragma region Variable
			float m_fScale = 0.0001;
			float m_Width = 10.0f;
			float m_Lenght = 10.0f;
			int m_nbPositionX = 0;
			int m_nbPositionY = -2;
			int m_nbPositionZ = 0;
			int m_nbRailSize = 30;
			list<Entity*> m_listEntityRails;
			Scene* m_scene;
		#pragma endregion

		RailManager();
		~RailManager();
		void CreateRails(Scene* scene);
		void RemoveRails();

	private :

};

