#include <Windows.h>

#pragma once
class Window
{
public:
	Window() {};
	~Window() {};
	bool init();
	bool release();
	bool broadcast();
	bool isRun();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);
	virtual void onCreate() {};
	virtual void onUpdate() {};
	virtual void onDestroy();
protected:
	HWND m_hwnd;
	bool m_isRun;
};

