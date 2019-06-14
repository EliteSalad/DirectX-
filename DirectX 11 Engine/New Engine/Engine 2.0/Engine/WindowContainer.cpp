#include "WindowContainer.h"



LRESULT WindowContainer::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	OutputDebugStringA("Window proc from window container\n");
	return  DefWindowProc(hwnd, uMsg, wParam, lParam);
}

WindowContainer::WindowContainer()
{
}


WindowContainer::~WindowContainer()
{
}
