#pragma once
#include <d3d11.h>
#include "SwapChain.h"

class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext *deviceContext);
	~DeviceContext();
	bool Release();
	bool clearRenderTargetColor(SwapChain* swapChain, float red, float green, float blue);
private:
	ID3D11DeviceContext *m_deviceContext;
};

