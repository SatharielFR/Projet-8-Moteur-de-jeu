#include "pch.h"
#include "framework.h"

//Constructeur
Engine::Engine(HWND hWnd)
{
    _hWnd = hWnd;
    InitD3D(_hWnd);
}

void Engine::Update()
{
    RenderFrame();
}

void Engine::Close()
{
    CleanD3D();
}

// this function initializes and prepares Direct3D for use
void Engine::InitD3D(HWND hWnd)
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
    InitGraphics();    // call the function to initialize the triangle

    d3ddev->SetRenderState(D3DRS_LIGHTING, FALSE);    // turn off the 3D lighting
    d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);    // both sides of the triangles
    d3ddev->SetRenderState(D3DRS_ZENABLE, TRUE);    // turn on the z-buffer


    //Create font
    D3DXFONT_DESC fontDesc;
    ZeroMemory(&fontDesc, sizeof(D3DXFONT_DESC));
    fontDesc.Height = 25;
    fontDesc.Width = 12;
    fontDesc.Weight = 500;
    fontDesc.MipLevels = D3DX_DEFAULT;
    fontDesc.Italic = false;
    fontDesc.CharSet = 0;
    fontDesc.OutputPrecision = 0;
    fontDesc.Quality = 0;
    fontDesc.PitchAndFamily = 0;
    char* test = (char*)fontDesc.FaceName;
    strcpy(test, "Times New Roman"); // font style
    D3DXCreateFontIndirect(d3ddev, &fontDesc, &Font);
}

// this is the function that puts the 3D models into video RAM
void Engine::InitGraphics(void)
{
    // create the vertices using the CUSTOMVERTEX struct
    CUSTOMVERTEX vertices[] =
    {
        /*{ -3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 0, 255), },
        { 3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { -3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(255, 0, 0), },
        { 3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 255), },*/

        // Vertex for cube 
      //{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },    // vertex 0
      //{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 0), },     // vertex 1
      //{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },   // 2
      //{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },  // 3
      //{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },     // ...
      //{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 0, 0), },
      //{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
      //{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 255), },

      // Vertex for pyramide
        // // base
        { -3.0f, 0.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
        { 3.0f, 0.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        { -3.0f, 0.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },
        { 3.0f, 0.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },

        //// top
        { 0.0f, 5.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },

        // Vertex the Hypercraft
        // fuselage
        //{ 3.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
        //{ 0.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        //{ 0.0f, 0.0f, 10.0f, D3DCOLOR_XRGB(255, 0, 0), },
        //{ -3.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 255), },

        //// left gun
        //{ 3.2f, -1.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        //{ 3.2f, -1.0f, 11.0f, D3DCOLOR_XRGB(0, 255, 0), },
        //{ 2.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(255, 0, 0), },

        //// right gun
        //{ -3.2f, -1.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
        //{ -3.2f, -1.0f, 11.0f, D3DCOLOR_XRGB(0, 255, 0), },
        //{ -2.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(255, 0, 0), },

    };

    //create a vertex buffer interface called v_buffer
    d3ddev->CreateVertexBuffer(5 * sizeof(CUSTOMVERTEX),
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
        // indice for cube
        //0, 1, 2,    // side 1
        //2, 1, 3,
        //4, 0, 6,    // side 2
        //6, 0, 2,
        //7, 5, 6,    // side 3
        //6, 5, 4,
        //3, 1, 7,    // side 4
        //7, 1, 5,
        //4, 5, 0,    // side 5
        //0, 5, 1,
        //3, 7, 2,    // side 6
        //2, 7, 6,

        // indice for pyramide
        0, 2, 1,    // base
        1, 2, 3,
        0, 1, 4,    // sides
        1, 3, 4,
        3, 2, 4,
        2, 0, 4,

        // indice the hypercraft
        //0, 1, 2,    // fuselage
        //2, 1, 3,
        //3, 1, 0,
        //0, 2, 3,
        //4, 5, 6,    // wings
        //7, 8, 9,

    };


    d3ddev->CreateIndexBuffer(18 * sizeof(short),    // 3 per triangle, 12 triangles
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

// this is the function used to render a single frame
void Engine::RenderFrame(void)
{
//    Update();

    D3DCOLOR ClearColor = D3DCOLOR_XRGB(255, 255, 255);

    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, ClearColor, 1.0f, 0);
    d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER, ClearColor, 1.0f, 0);

    d3ddev->BeginScene();


    //Test Print text
    //Create Font
    //Create Rectangle to draw the font
    RECT  Rec;
    Rec.left = 20;
    Rec.top = 20;
    Rec.right = SCREEN_WIDTH;
    Rec.bottom = SCREEN_HEIGHT;
    //Display the font text using the rect and font
    std::wstring w = L"Groupe 1 : Janaky / Leo / Rodrigue / Tom";;
    const WCHAR* wcharTextToDisplay = w.c_str();
    LPCWSTR textToDisplay = LPCWSTR(wcharTextToDisplay);
    if (Font)
    {
        Font->DrawText(
            NULL,
            textToDisplay, // String to draw.
            -1, // Null terminating string.
            &Rec, // Rectangle to draw the string in.
            DT_TOP | DT_LEFT, // Draw in top-left corner of rect.
            0xff000000); // Black.

    }
    //end test print text

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

    //D3DXMATRIX matScaling;
    //D3DXMATRIX matTranslate;    // a matrix to store the translation for triangle A
    //D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
    static float index = 0.0f; index += 0.05f; // an ever-increasing float value

    Transform test;
    test.Rotate(index, 2.5f, 1.5f);
    //test.Scaling(0.5f, 0.5f, 0.5f);
    test.ScalingUniforme(0.5f);
    //D3DXMatrixScaling(&matScaling, 0.5f, 0.5f, 0.5f);

    ////D3DXMatrixRotationY(&matRotateY, index);    // the front side
    ////(&matRotateY, index);
    //D3DXMatrixRotationZ(&matRotateY, index);

    //// build MULTIPLE matrices to translate the model and one to rotate
    //D3DXMatrixTranslation(&matTranslate, 0.0f, 0.0f, 2.0f);


    //D3DXMATRIX matResult = matScaling * matRotateY * matTranslate;


    // tell Direct3D about each world transform, and then draw another triangle
    d3ddev->SetTransform(D3DTS_WORLD, &test.m_matrix);

    // draw the cube
   // d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

    // draw the pyramid
    d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 5, 0, 6);

    // draw the Hypercraft
    //d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 10, 0, 6);

    //d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
   // d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

    //d3ddev->SetTransform(D3DTS_WORLD, &matResultB);
   // d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
   // d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

    d3ddev->EndScene();

    d3ddev->Present(NULL, NULL, NULL, NULL);
}

// this is the function that cleans up Direct3D and COM
void Engine::CleanD3D(void)
{
    v_buffer->Release();    // close and release the vertex buffer
    d3ddev->Release();    // close and release the 3D device
    d3d->Release();    // close and release Direct3D
}


