#include "pch.h"
#include "framework.h"

Transform::Transform()
{
	Identity();
}

void Transform::Begin()
{
//	Identity();
}

void Transform::Identity()
{
	m_vSca.x = 1.0f;
	m_vSca.y = 1.0f;
	m_vSca.z = 1.0f;
	D3DXMatrixIdentity(&m_matSca);

	m_vPos.x = 0.0f;
	m_vPos.y = 0.0f;
	m_vPos.z = 0.0f;
	D3DXMatrixIdentity(&m_matPos);

	D3DXMatrixIdentity(&m_matRot);
	m_vDir = { 0.0f, 0.0f, 1.0f };
	m_vRight = { 1.0f, 0.0f, 0.0f };
	m_vUp = { 0.0f, 1.0f, 0.0f };
	D3DXQuaternionIdentity(&m_qRot);

	D3DXMatrixIdentity(&m_matrix);
}

void Transform::UpdateMatrix()
{
	m_matrix = m_matSca;
	m_matrix *= m_matRot;
	m_matrix *= m_matPos;
}

//Y X Z
void Transform::Rotate(float pitch, float yaw, float roll)
{
	D3DXQUATERNION	quat;
	D3DXQUATERNION quatRot;
	D3DXQuaternionIdentity(&quatRot);


	D3DXQuaternionRotationAxis(&quat, &m_vRight, pitch); // Axe  X
	quatRot *= quat;

	D3DXQuaternionRotationAxis(&quat, &m_vUp, yaw); // Axe Y 
	quatRot *= quat;

	D3DXQuaternionRotationAxis(&quat, &m_vDir, roll); // Axe Z
	quatRot *= quat;

	m_qRot *= quatRot;

	D3DXMatrixRotationQuaternion(&m_matRot, &m_qRot);

	m_vRight.x = m_matRot._11;
	m_vRight.y = m_matRot._12;
	m_vRight.z = m_matRot._13;
	m_vUp.x = m_matRot._21;
	m_vUp.y = m_matRot._22;
	m_vUp.z = m_matRot._23;
	m_vDir.x = m_matRot._31;
	m_vDir.y = m_matRot._32;
	m_vDir.z = m_matRot._33;

	UpdateMatrix();
}

void Transform::Scaling(float x, float y, float z)
{
	m_vSca.x = x;
	m_vSca.y = y;
	m_vSca.z = z;
	D3DXMatrixScaling(&m_matSca, x,y,z);
	UpdateMatrix();
}

void Transform::ScalingUniforme(float scale) 
{
	m_vSca.x = scale;
	m_vSca.y = scale;
	m_vSca.z = scale;
	D3DXMatrixScaling(&m_matSca, scale, scale, scale);
	UpdateMatrix();
}

void Transform::Move(float x, float y, float z) 
{
	m_vPos.x += x;
	m_vPos.y += y;
	m_vPos.z += z;
	D3DXMatrixTranslation(&m_matPos, m_vPos.x, m_vPos.y, m_vPos.z);
	UpdateMatrix();
}

void Transform::MoveUniforme(float dist)
{
	m_vPos += m_vDir * dist;
	D3DXMatrixTranslation(&m_matPos, m_vPos.x, m_vPos.y, m_vPos.z);
	UpdateMatrix();
}

void Transform::SetPosition(float x, float y, float z)
{
	m_vPos.x = x;
	m_vPos.y = y;
	m_vPos.z = z;
	D3DXMatrixTranslation(&m_matPos, x, y, z);
	UpdateMatrix();
}
