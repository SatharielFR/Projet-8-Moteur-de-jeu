#include "pch.h"
#include "Transform.h"

Transform::Transform()
{
	Identity();
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

void Transform::Rotate(float yaw, float pitch, float roll)
{
	D3DXQUATERNION	quat;
	D3DXQUATERNION quatRot;
	D3DXQuaternionIdentity(&quatRot);

	D3DXQuaternionRotationAxis(&quat, &m_vDir, 0.5f); // Axe Z
	quatRot *= quat;

	D3DXQuaternionRotationAxis(&quat, &m_vRight, 0.0f); // Axe  X
	quatRot *= quat;

	D3DXQuaternionRotationAxis(&quat, &m_vUp, 1.0f); // Axe Y 
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

	//D3DXMatrixScaling(&m_matSca, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixTranslation(&m_matPos, 0.0f, 0.0f, 2.0f);
	//D3DXMatrixRotationY(&m_matRot, 3.14f);

	UpdateMatrix();
}
