#include "Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Engine engine;
	engine.Initilize(hInstance, "Title", "WindowClass", 800, 600);

	//pm returns true if window is active and false if destroyed
	while (engine.ProcessMessages() == true)
	{
		Sleep(50);
	}
	return 0;
}