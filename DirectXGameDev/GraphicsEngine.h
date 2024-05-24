#pragma once
#include <d3d11.h>
#include "SwapChain.h"
class SwapChain;

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
	bool init();
	bool release();
public:
	SwapChain* createSwapChain();
	static GraphicsEngine* get();
private:
	ID3D11Device* m_d3dDevice;
	D3D_FEATURE_LEVEL m_featureLevel;
	ID3D11DeviceContext *m_immContext;
private:
	IDXGIDevice *m_dxgiDevice;
	IDXGIAdapter *m_dxgiAdapter;
	IDXGIFactory *m_dxgiFactory;
private:
	friend class SwapChain;
};
