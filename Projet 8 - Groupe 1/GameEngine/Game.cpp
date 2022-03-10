
#include "Game.h"


// define the screen resolution
//#define SCREEN_WIDTH  1920
//#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH  800 
#define SCREEN_HEIGHT 800
#define MAX_LOADSTRING 100

//Struct for 3D
struct CUSTOMVERTEX { FLOAT X, Y, Z; DWORD COLOR; };
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

#pragma region GlobalVariables
    HINSTANCE hInst;                                // instance actuelle
    WCHAR szTitle[MAX_LOADSTRING];                  // Texte de la barre de titre
    WCHAR szWindowClass[MAX_LOADSTRING];            // nom de la classe de fenêtre principale

    D3DXMATRIX matView;    // the view transform matrix
    D3DXVECTOR3 vecCamPosition = D3DXVECTOR3(0.0f, 0.0f, 15.0f);   // the camera position
    D3DXVECTOR3 vecLookAtPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);    // the look-at position
    D3DXVECTOR3 vecUpDirection = D3DXVECTOR3(0.0f, 1.0f, 0.0f);    // the up direction
#pragma endregion

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// the entry point for any Windows program
int WINAPI WinMain( HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int nCmdShow)
{
    HWND hWnd;
    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"WindowClass";

    RegisterClassEx(&wc);

  hWnd = CreateWindowEx(NULL, L"WindowClass", L"Our Direct3D Program",
                          WS_OVERLAPPEDWINDOW, 300, 300, SCREEN_WIDTH, SCREEN_HEIGHT,
                          NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    // set up and initialize Direct3D
    initD3D(hWnd);

    // enter the main loop:

    MSG msg;

    while (TRUE)
    {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (msg.message == WM_QUIT)
            break;

        render_frame();
    }

    // clean up DirectX and COM
    cleanD3D();

    return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    } break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

/// 
///     Fonctions DirectX 3D
/// 

// this function initializes and prepares Direct3D for use
void initD3D(HWND hWnd)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

    D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

    ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
    d3dpp.Windowed = TRUE;    // FALSE - program windowed, not fullscreen
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
    d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
    d3dpp.BackBufferWidth = SCREEN_WIDTH;    // set the width of the buffer
    d3dpp.BackBufferHeight = SCREEN_HEIGHT;    // set the height of the buffer
    d3dpp.EnableAutoDepthStencil = TRUE;    // automatically run the z-buffer for us
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;    // 16-bit pixel format for the z-buffer

    // create a device class using this information and information from the d3dpp stuct
    d3d->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &d3ddev);
    init_graphics();    // call the function to initialize the triangle

    d3ddev->SetRenderState(D3DRS_LIGHTING, FALSE);    // turn off the 3D lighting
    d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);    // both sides of the triangles
    d3ddev->SetRenderState(D3DRS_ZENABLE, TRUE);    // turn on the z-buffer
}

// this is the function used to render a single frame
void render_frame(void)
{
    Update();

    D3DCOLOR ClearColor = D3DCOLOR_XRGB(255, 255, 255);

    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, ClearColor, 1.0f, 0);
    d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER,ClearColor, 1.0f, 0);

    d3ddev->BeginScene();

    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    // set the view transform
    D3DXMatrixLookAtLH(&matView,
        &vecCamPosition,   // the camera position
        &vecLookAtPosition,    // the look-at position
        &vecUpDirection);    // the up direction
    d3ddev->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView

    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
        D3DXToRadian(45),    // the horizontal field of view
        (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT, // aspect ratio
        1.0f,    // the near view-plane
        100.0f);    // the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);     // set the projection


    // select the vertex buffer to display
    d3ddev->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
    d3ddev->SetIndices(i_buffer);

    D3DXMATRIX matTranslateA;    // a matrix to store the translation for triangle A
    D3DXMATRIX matTranslateB;    // a matrix to store the translation for triangle B
    D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
    static float index = 0.0f; index += 0.05f; // an ever-increasing float value

    // build MULTIPLE matrices to translate the model and one to rotate
    D3DXMatrixTranslation(&matTranslateA, 0.0f, 0.0f, 2.0f);
    D3DXMatrixTranslation(&matTranslateB, 0.0f, 0.0f, -2.0f);
    D3DXMatrixRotationY(&matRotateY, index);    // the front side
    //D3DXMatrixRotationX(&matRotateY, index);
    //D3DXMatrixRotationZ(&matRotateY, index);
    D3DXMATRIX matResultA = matTranslateA * matRotateY;
    D3DXMATRIX matResultB = matTranslateB * matRotateY;

    // tell Direct3D about each world transform, and then draw another triangle
    d3ddev->SetTransform(D3DTS_WORLD, &matResultA);

    // draw the cube
    d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

    //d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
   // d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

    d3ddev->SetTransform(D3DTS_WORLD, &matResultB);
   // d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
   // d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

    d3ddev->EndScene();

    d3ddev->Present(NULL, NULL, NULL, NULL);
}

// this is the function that cleans up Direct3D and COM
void cleanD3D(void)
{
    v_buffer->Release();    // close and release the vertex buffer
    d3ddev->Release();    // close and release the 3D device
    d3d->Release();    // close and release Direct3D
}

// this is the function that puts the 3D models into video RAM
void init_graphics(void)
{
    // create the vertices using the CUSTOMVERTEX struct
    CUSTOMVERTEX vertices[] =
    {
        /*{ -3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 0, 255), },
        { 3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { -3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(255, 0, 0), },
        { 3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 255), },*/

      { -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },    // vertex 0
      { 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 0), },     // vertex 1
      { -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },   // 2
      { 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },  // 3
      { -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },     // ...
      { 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 0, 0), },
      { -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
      { 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 255), },
    };

    //create a vertex buffer interface called v_buffer
    d3ddev->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX),
        0,
        CUSTOMFVF,
        D3DPOOL_MANAGED,
        &v_buffer,
        NULL);

    VOID* pVoid;    // a void pointer

    // lock v_buffer and load the vertices into it
    v_buffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, vertices, sizeof(vertices));
    v_buffer->Unlock();


    // create the indices using an int array
    short indices[] =
    {
        0, 1, 2,    // side 1
        2, 1, 3,
        4, 0, 6,    // side 2
        6, 0, 2,
        7, 5, 6,    // side 3
        6, 5, 4,
        3, 1, 7,    // side 4
        7, 1, 5,
        4, 5, 0,    // side 5
        0, 5, 1,
        3, 7, 2,    // side 6
        2, 7, 6,
    };



    d3ddev->CreateIndexBuffer(36 * sizeof(short),    // 3 per triangle, 12 triangles
        0,
        D3DFMT_INDEX16,
        D3DPOOL_MANAGED,
        &i_buffer,
        NULL
    );

    // lock i_buffer and load the indices into it
    i_buffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, indices, sizeof(indices));
    i_buffer->Unlock();
}

/// 
///     Custom Functions
/// 

#pragma region GlobalVariable
    float g_fForwardValue = 0;
    float g_fHorizontalValue = 0;
    float g_fSpeed = 0.5f;
#pragma endregion


void Update()
{
    UpdateInputs();
    UpdateCameraPosition();
}

//Detect Inputs
void UpdateInputs()
{
    //Forward inputs
    if (GetKeyState('Z') & 0x8000)
    {
        g_fForwardValue = 1;
    }
    else if (GetKeyState('S') & 0x8000)
    {
        g_fForwardValue = -1;
    }
    else
    {
        g_fForwardValue = 0;
    }

    //Horizontal inputs
    if (GetKeyState('Q') & 0x8000)
    {
        g_fHorizontalValue = 1;
    }
    else if (GetKeyState('D') & 0x8000)
    {
        g_fHorizontalValue = -1;
    }
    else
    {
        g_fHorizontalValue = 0;
    }
}

void UpdateCameraPosition()
{
    vecCamPosition.x += g_fHorizontalValue  * g_fSpeed;
    vecCamPosition.z += g_fForwardValue     * g_fSpeed;

}