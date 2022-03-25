#include "Cart.h"

Cart::Cart(Scene* scene)
{
    m_scene = scene;
    //Create the Cart
    m_entityCart = new Entity();
    m_scene->AddEntity(m_entityCart);
    MeshComponent* l_meshComponentCart = new MeshComponent();
    l_meshComponentCart->SetMeshAndTexturePath("..\\Ressources\\Cube.x");
    m_entityCart->AddComponent(l_meshComponentCart);
    //Init Cart position
    m_entityCart->transform->m_transform->Move(0.0f, 1.0f, 0.0f);
//    m_entityCart->transform->m_transform->Rotate(45.0f, 45.0f, 0.0f);
    m_entityCart->transform->m_transform->ScalingUniforme(0.01f);
}

Cart::~Cart()
{
}