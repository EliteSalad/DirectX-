#pragma once
#include "ErrorLogger.h"

class WindowContainer;		//foward decleration to avoid circular depndancy

class RenderWindow
{
public:
	bool Initilize(WindowContainer * pWindowContainer, HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
	///handle to instance,	window title,	window class name,	width,	height;
	bool ProcessMessages();

	~RenderWindow();
private:
	void RegisterWindowClass();
	HWND m_handle = NULL; //handle to this window
	HINSTANCE m_hInstance = NULL; //Handle to application instance
	std::string m_window_title = "";
	std::wstring m_window_title_wide = L""; //Wide string representation of window title
	std::string m_window_class = "";
	std::wstring m_window_class_wide = L""; // Wide string representation of window class name
	int m_width = 0;
	int m_height = 0;
};


