#pragma once
#include <list>
#include "framework.h"


enum enumDirection
{
	Forward, Backward, Right, Left
};

class RailManager
{
	public :
		#pragma region Variable
			float m_fScale = 0.02;
			float m_Width = 4.0f;
			float m_Lenght = 4.0f;
			int m_nbPositionX = 0;
			int m_nbPositionY = 0.01;
			int m_nbPositionZ = 0;
			int m_nbRailSize = 4;
			enumDirection m_currentDirection = enumDirection::Forward;
			list<Entity*> m_listEntityRails;
			Scene* m_scene;
		#pragma endregion

		RailManager();
		~RailManager();
		void CreateRails(Scene* scene);
		void RemoveRails();

	private :

};

