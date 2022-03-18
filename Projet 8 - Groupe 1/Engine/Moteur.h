#pragma once

#pragma region DirectX
	// include the basic windows header files and the Direct3D header file
	#pragma comment(lib, "d3d9.lib")
	#ifdef _DEBUG
	#pragma comment(lib, "d3dx9d.lib")
	#else
	#pragma comment(lib, "d3dx9.lib")
	#endif

	#include <d3d9.h>
	#include <d3dx9.h>
	//// include the Direct3D Library file
	//#pragma comment (lib, "d3d9.lib")
	//#pragma comment (lib, "d3dx9.lib")
#pragma endregion

#pragma region SystIncludes
	// Fichiers d'en-tête Windows
	#include <windows.h>
	#include <windowsx.h>
	//To use Time
	#include <mmsystem.h> 
	#pragma comment(lib, "winmm.lib")
	// Fichiers d'en-tête C RunTime
	#include <stdlib.h>
	#include <malloc.h>
	#include <memory.h>
	#include <tchar.h>
	#include <string>
	#include <iostream>
	#include <list>
	#include<vector>
	using namespace std;
	// Engine classes
	//#include "pch.h"
#pragma endregion

#pragma region Engine
	#include "Engine.h"
	#include "SceneManager.h"
	#include "Timer.h"
	#include "Transform.h"
	#include "Entity.h"
	#include "Scene.h"
	#include "Debug.h"
	#include "Component.h"
	#include "Texturing.h"
	#include "MeshComponent.h"
	#include "TransformComponent.h"
    #include "Camera.h"
#pragma endregion

#pragma region GlobalVariables
	// define the screen resolution
	//#define SCREEN_WIDTH  1920
	//#define SCREEN_HEIGHT 1080
	#define SCREEN_WIDTH  800
	#define SCREEN_HEIGHT 800
	#define MAX_LOADSTRING 100
	//Struct for 3D
	struct CUSTOMVERTEX { FLOAT X, Y, Z; DWORD COLOR; static const DWORD FVF; };
	#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)
#pragma endregion

