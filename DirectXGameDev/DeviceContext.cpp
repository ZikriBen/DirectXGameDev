#include "DeviceContext.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* deviceContext) : m_deviceContext(deviceContext)
{
}

DeviceContext::~DeviceContext()
{
}

bool DeviceContext::Release()
{
	m_deviceContext->Release();
	delete this;
	return true;
}

bool DeviceContext::clearRenderTargetColor(SwapChain* swapChain, float red, float green, float blue)
{
	FLOAT clear_color[] = { red, green, blue };
	m_deviceContext->ClearRenderTargetView(swapChain->m_rtv, clear_color);
	return true;
}
