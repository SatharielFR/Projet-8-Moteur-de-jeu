#pragma once
#include "framework.h"
#include "Target.h"
#include "RailManager.h"

class TargetSpawner
{
	public :
		#pragma region PublicFunctions
			TargetSpawner(Scene* scene, RailManager* railManager);
			~TargetSpawner();
			void Reset();
			void SpawnTargets();
			void Close();
		#pragma endregion
	private :
		#pragma region PrivateVariables
			float _fSpawnPercentChance;
			float _fSpawnRange;
			Scene* _scene;
			list<Target*> _lstTarget;
			RailManager* _railManager;
			MeshComponent* _meshComponentTarget;
		#pragma endregion

		#pragma region PrivateFunctions
		#pragma endregion
};

