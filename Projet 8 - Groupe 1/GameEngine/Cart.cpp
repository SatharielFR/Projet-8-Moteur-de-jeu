#include "Cart.h"
#include "RailManager.h"

Cart::Cart(Scene* scene, RailManager* railManager)
{
    m_scene = scene;
    m_railManager = railManager;
    //Create the Cart
    m_entityCart = new Entity();
    m_scene->AddEntity(m_entityCart);
    MeshComponent* l_meshComponentCart = new MeshComponent();
    l_meshComponentCart->SetMeshAndTexturePath("..\\Ressources\\Cart.x");
    m_entityCart->AddComponent(l_meshComponentCart);
    //Init Cart position
    m_entityCart->transform->m_transform->Move(0.0f, 1.0f, 0.0f);
//    m_entityCart->transform->m_transform->Rotate(45.0f, 45.0f, 0.0f);
    m_entityCart->transform->m_transform->ScalingUniforme(0.01f);
}

Cart::~Cart()
{
}

void Cart::UpdateSpeed()
{
    if (_nbForwardValue == -1)
    {
        _fCartSpeed = 0;
    }
    if (_nbForwardValue == 0)
    {
        _fCartSpeed = 0;
    }
    if (_nbForwardValue == 1)
    {
        _fCartSpeed = _fCartDefaultSpeed;
    }
    if (_nbForwardValue == 2)
    {
        _fCartSpeed = _fCartBoostSpeed;
    }
}

void Cart::SetForwardValue(int value)
{
    _nbForwardValue = value;
}

void Cart::Update()
{
    UpdateSpeed();
    if (m_currentRailEntity == nullptr)
    {
        _vec3NewLocation = new D3DXVECTOR3();
        _quatnewRotation = new D3DXQUATERNION();
        itRail = m_railManager->m_listEntityRails.begin();
        //Set reference to the first Rail of the list
        m_currentRailEntity = *itRail;
        _vec3LerpStart = &m_currentRailEntity->transform->m_transform->m_vPos;
        _quatLerpStart = &m_currentRailEntity->transform->m_transform->m_qRot;
        m_currentRailEntity = *(++itRail);
        _vec3LerpEnd = &m_currentRailEntity->transform->m_transform->m_vPos;
        _quatLerpEnd = &m_currentRailEntity->transform->m_transform->m_qRot;
    }
    else
    {
        //When the lerp is complete
        if (_fLerpValue == 1)
        {
            //Set the new destination to the next rail
            if (itRail != --m_railManager->m_listEntityRails.end())
            {
                _vec3LerpStart = &m_currentRailEntity->transform->m_transform->m_vPos;
                _quatLerpStart = &m_currentRailEntity->transform->m_transform->m_qRot;
                ++itRail;
                m_currentRailEntity = *(itRail);
                _vec3LerpEnd = &m_currentRailEntity->transform->m_transform->m_vPos;
                _quatLerpEnd = &m_currentRailEntity->transform->m_transform->m_qRot;
                _fLerpValue = 0;
            }
            else
            {
                _bHasReachEnd = true;
            }
        }
    }

    //Increase lerp Value
    _fLerpValue = _fLerpValue + _fCartSpeed * Timer::s_inst->GetDeltaTime();
    if (_fLerpValue > 1) { _fLerpValue = 1; }

    //Lerp Values
    D3DXVec3Lerp(_vec3NewLocation, _vec3LerpStart, _vec3LerpEnd, _fLerpValue);              //Postion
    D3DXQuaternionSlerp(_quatnewRotation, _quatLerpStart, _quatLerpEnd, _fLerpValue);       //Rotation

    //Set New location
    m_entityCart->transform->m_transform->SetPosition( _vec3NewLocation->x,
                                                       _vec3NewLocation->y,
                                                       _vec3NewLocation->z);

    //TODO : Set New rotation

}

void Cart::Reset()
{
    _bHasReachEnd = false;
    //Init Cart position
    m_entityCart->transform->m_transform->Move(0.0f, 1.0f, 0.0f);
    //Reset Current rail
    m_currentRailEntity = nullptr;
}

D3DXVECTOR3 Cart::GetCartPosition()
{
    return m_entityCart->transform->m_transform->m_vPos;
}
