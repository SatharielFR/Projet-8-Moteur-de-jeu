#pragma once

class Transform
{
	public:
		#pragma region  Variables
			D3DXVECTOR3			m_vSca;
			D3DXMATRIX			m_matSca;
			D3DXVECTOR3			m_vDir;
			D3DXVECTOR3			m_vRight;
			D3DXVECTOR3			m_vUp;
			D3DXMATRIX			m_matRot;
			D3DXQUATERNION		m_qRot;
			D3DXVECTOR3			m_vPos;
			D3DXMATRIX			m_matPos;
			D3DXMATRIX			m_matrix;
		#pragma endregion

		#pragma region PublicFunction
			Transform();
			void Identity();
			void UpdateMatrix();
			void Rotate(float yaw, float pitch, float roll);
			
			void Scaling( float x, float y, float z);
			void ScalingUniforme(float scale);
			void Move(float x, float y, float z);
			void MoveUniforme(float dist);
			void SetPosition(float x, float y, float z);
		#pragma endregion 
};

