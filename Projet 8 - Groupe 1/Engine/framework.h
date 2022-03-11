#pragma once

// Fichiers d'en-tête Windows
#include <windows.h>
#include <windowsx.h>
// Fichiers d'en-tête C RunTime
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//Windows
#include <Windows.h>
#pragma comment(lib, "d3d9.lib")
#ifdef _DEBUG
#pragma comment(lib, "d3dx9d.lib")
#else
#pragma comment(lib, "d3dx9.lib")
#endif

//Include Engine
#include "Engine.h"