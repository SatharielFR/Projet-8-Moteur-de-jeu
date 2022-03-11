#pragma once

#pragma comment(lib, "d3d9.lib")
#ifdef _DEBUG
#pragma comment(lib, "d3dx9d.lib")
#else
#pragma comment(lib, "d3dx9.lib")
#endif

//#define WIN32_LEAN_AND_MEAN             // Exclure les en-têtes Windows rarement utilisés


//Windows
#include <Windows.h>
#include <d3dx9.h>

//Include Engine
#include "Engine.h"