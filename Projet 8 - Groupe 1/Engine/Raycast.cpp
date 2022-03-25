#include "pch.h"
#include "framework.h"

Raycast Raycast::CalcPickingRay(int mouse_x, int mouse_y)
{
    float px = 0.0f;
    float py = 0.0f;

    // Get Projection matrix
    D3DXMATRIX proj;
    Engine::d3ddev->GetTransform(D3DTS_PROJECTION, &proj);

    px = (((2.0f * mouse_x) / SCREEN_WIDTH) - 1.0f) / proj(0, 0);
    py = (((-2.0f * mouse_y) / SCREEN_HEIGHT) + 1.0f) / proj(1, 1);

    Raycast ray;
    ray.origin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    ray.direction = D3DXVECTOR3(px, py, 1.0f);

    return ray;
}

void Raycast::TransformRay(Raycast* ray, D3DXMATRIX* invertViewMatrix)
{
    // transform the ray's origin, w = 1.
    D3DXVec3TransformCoord(
        &ray->origin,
        &ray->origin,
        invertViewMatrix);

    // transform the ray's direction, w = 0.
    D3DXVec3TransformNormal(
        &ray->direction,
        &ray->direction,
        invertViewMatrix);

    // normalize the direction
    D3DXVec3Normalize(&ray->direction, &ray->direction);
}
