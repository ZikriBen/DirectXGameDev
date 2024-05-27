#include <d3d11.h>
#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
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

    ID3D11DeviceContext* m_immContext;
    
    for (UINT driverType_index = 0; driverType_index < numDriverType;) {

        res = D3D11CreateDevice(NULL, driverTypes[driverType_index], NULL, NULL, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &m_d3dDevice, &m_featureLevel, &m_immContext);
        
        if (SUCCEEDED(res)) 
            break;
            driverType_index++;
    }

    if (FAILED(res)) {
        return false;
    }

    m_deviceContext = new DeviceContext(m_immContext);

    m_d3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void **)&m_dxgiDevice);
    m_dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgiAdapter);
    m_dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgiFactory);

    return true;
}

bool GraphicsEngine::release()
{
    m_d3dDevice->Release();
    m_dxgiAdapter->Release();
    m_dxgiFactory->Release();
    m_deviceContext->Release();
    delete this;
    return true;
}

SwapChain* GraphicsEngine::createSwapChain()
{
    return new SwapChain();
}

GraphicsEngine* GraphicsEngine::get()
{
    static GraphicsEngine engine;
    return &engine;
}
DeviceContext* GraphicsEngine::getImmediateDeviceContext()
{
    return this->m_deviceContext;
}
GraphicsEngine::~GraphicsEngine()
{
}