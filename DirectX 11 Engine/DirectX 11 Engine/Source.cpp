#include <d3d11.h>
#include <dxgi.h>
#include <windows.h>
#include <tchar.h>


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	D3D11CreateDeviceAndSwapChain(NULL,
		D3D_DRIVER_TYPE_REFERENCE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL);

	MessageBoxA(NULL, "Hello World!", "[Game Engine]", MB_OK);

	return 0;
}

//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR lpCmdLine,
//	_In_ int nCmdShow)
//{
//	return 0;
//}