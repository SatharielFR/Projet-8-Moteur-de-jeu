#pragma once

//TODO : Supprimer ca quand tout aurras été fait dans l engine 
// include the basic windows header files and the Direct3D header file
#include <d3d9.h>
#include <d3dx9.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")


// global declarations
LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;    // the pointer to the vertex buffer
LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;     // the pointer to the index buffer

// Fichiers d'en-tête C RunTime
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>



class Engine
{
	public:
		#pragma region PublicVariables

		#pragma endregion 

		#pragma region PublicFunctions
			Engine();
		#pragma endregion 

	private:
		#pragma region PrivateVariables
		#pragma endregion 

		#pragma region PrivateFunctions
		#pragma endregion 
};