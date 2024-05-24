#include <d3d11.h>
#pragma once
class SwapChain
{
public:
	SwapChain();
	~SwapChain();
	bool init(HWND hwnd, UINT width, UINT height);
	bool release();
private:
	IDXGISwapChain* m_swapChain;
};

