#include "AppWindow.h"

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get()->init();
	m_swapChain = GraphicsEngine::get()->createSwapChain();
	
	RECT rc = this->getClientWindowRect();
	m_swapChain->init(this->m_hwnd, rc.right - rc.left, rc.bottom - rc.top);

}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(this->m_swapChain, 0.0f, 1.0f, 0.0f);

	m_swapChain->present(false);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_swapChain->release();
	GraphicsEngine::get()->release();
}
