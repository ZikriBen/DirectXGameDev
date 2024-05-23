#include <Windows.h>

#pragma once
class Window
{
public:
	Window();
	~Window();
	bool init();
	bool release();
	bool broadcast();
	bool isRun();
	virtual void onCreate() {};
	virtual void onUpdate() {};
	virtual void onDestroy();
private:
	HWND m_hwnd;
	bool m_isRun;
};

