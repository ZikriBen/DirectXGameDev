#include <d3d11.h>
#pragma once

class DeviceContext;
class SwapChain
{
public:
	SwapChain();
	~SwapChain();
	bool init(HWND hwnd, UINT width, UINT height);
	bool release();
	bool present(bool vsync);
private:
	IDXGISwapChain* m_swapChain;
	ID3D11RenderTargetView* m_rtv;
	friend class DeviceContext;
};

