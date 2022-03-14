#pragma once


//Attention : Deja définit dans les Variables d'environement du projet

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/Engine.lib")
#else 
#pragma comment(lib, "../x64/Release/Engine.lib")
#endif // DEBUG


#include "targetver.h"
#include "../Engine/Moteur.h"	//Link to our Engine

