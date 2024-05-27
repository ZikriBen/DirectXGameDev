#include "SwapChain.h"
#include "GraphicsEngine.h"


SwapChain::SwapChain()
{
}

SwapChain::~SwapChain()
{
}

bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{
	ID3D11Device *device = GraphicsEngine::get()->m_d3dDevice;
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1;
	desc.BufferDesc.Width = width;
	desc.BufferDesc.Height = height;
	desc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Numerator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hwnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;
	HRESULT res = GraphicsEngine::get()->m_dxgiFactory->CreateSwapChain(device, &desc, &m_swapChain);
	
	
	if (FAILED(res)) {
		return false;
	}
	ID3D11Texture2D* buffer = NULL;
	res = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

	if (FAILED(res)) {
		return false;
	}

	res = device->CreateRenderTargetView(buffer, NULL, &m_rtv);
	buffer->Release();

	if (FAILED(res)) {
		return false;
	}

	return true;
}

bool SwapChain::release()
{
	m_swapChain->Release();
	delete this;
	return true;
}

bool SwapChain::present(bool vsync)
{
	m_swapChain->Present(vsync, NULL);
	return true;
}
