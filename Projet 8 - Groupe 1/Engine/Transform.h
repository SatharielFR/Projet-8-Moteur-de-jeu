#pragma once

#include "Engine.h"

//#include <D3DX10math.h>
//// include the Direct3D Library file
//#pragma comment (lib, "D3DX10math.lib")

class Transform
{
	public:
		#pragma region  Variables
			D3DMATRIX			m_vec3Sca;
			D3DVECTOR			m_vec3Dir;
			D3DVECTOR			m_vec3Right;
			D3DVECTOR			m_veec3Up;
			D3DXQUATERNION		m_quatRot;
			D3DXMATRIX			m_matrixRot;
			D3DVECTOR			m_vec3Pos;
			D3DXMATRIX			m_matrix;
		#pragma endregion

		#pragma region PublicFunction
			Transform();
			void Identity();
			void FromMatrix(D3DMATRIX* pMat);
			void UpdateRotationFromVectors();
			void UpdateRotationFromQuaternion();
			void UpdateRotationFromMatrix();
			void UpdateMatrix();
			void Rotate(float yaw, float pitch, float roll);
			void RotateYaw(float angle);
			void RotatePitch(float angle);
			void RotateRoll(float angle);
			void RotateWorld(D3DMATRIX* pMatrix);
			void RotateWorldX(float angle);
			void RotateWorldY(float angle);
			void RotateWorldZ(float angle);
		#pragma endregion 
};

