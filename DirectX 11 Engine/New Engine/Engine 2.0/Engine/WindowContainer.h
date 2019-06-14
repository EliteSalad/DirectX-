#pragma once
#include "RenderWindow.h"

class WindowContainer
{
	
public:
	//WindwProc
	//Mouse
	//Keyboard
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	WindowContainer();
	~WindowContainer();
protected:
	RenderWindow render_window;
private:

};

