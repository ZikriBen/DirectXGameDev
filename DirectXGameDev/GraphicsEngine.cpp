#include <d3d11.h>
#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
    D3D_DRIVER_TYPE driverTypes[] = {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };
    UINT numDriverType = ARRAYSIZE(driverTypes);
    
    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_0
    };
    UINT numFeatureLevels = ARRAYSIZE(featureLevels);
    HRESULT res = 0;
    
    for (UINT driverType_index = 0; driverType_index < numDriverType;) {

        res = D3D11CreateDevice(NULL, driverTypes[driverType_index], NULL, NULL, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &m_d3dDevice, &m_featureLevel, &m_immContext);
        
        if (SUCCEEDED(res)) 
            break;
            driverType_index++;
    }

    if (FAILED(res)) {
        return false;
    }

    return true;
}

bool GraphicsEngine::release()
{
    m_immContext->Release();
    m_d3dDevice->Release();
    return true;
}

GraphicsEngine* GraphicsEngine::get()
{
    static GraphicsEngine engine;
    return &engine;
}
