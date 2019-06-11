#include "RenderWindow.h"



bool RenderWindow::Initilize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	///save window details
	m_hInstance = hInstance;
	m_window_title = window_title;
	m_window_class = window_class;
	m_window_title_wide = StringConverter::StringToWide(m_window_title);
	m_window_class_wide = StringConverter::StringToWide(m_window_class);
	m_height = height;
	m_width = width;

	///register windows
	RegisterWindowClass();

	///create window
	m_handle = CreateWindowEx(
		0,											//Extended windows style
		m_window_class_wide.c_str(),				//window class name
		m_window_title_wide.c_str(),				//window title
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,	//windows style
		0,											//window x position
		0,											//window y position
		m_width,									//widnow width
		m_height,									//window height
		NULL,										//handle to parent window
		NULL,										//handle to child window
		m_hInstance,								//instance used
		nullptr);									//create window param

	///check winow has been succesfully made if not display error 
	if (m_handle == NULL)
	{
		ErrorLogger::Log(GetLastError(), "Window failed to create " + m_window_title);
		//window doesn't throws handle instead of h result, getlasterror to get the hresult. 
		return false;
	}

	///Display window
	ShowWindow(m_handle, SW_SHOW);		//displays window
	SetForegroundWindow(m_handle);		//sets window as foreground
	SetFocus(m_handle);					//set as focus

	return true;
}

bool RenderWindow::ProcessMessages()
{
	//handle windows messages
	MSG msg;	//create msg to store the windows message
	ZeroMemory(&msg, sizeof(MSG));	//zero memore / make null

	///peak message isnt blockign like get message
	if (PeekMessage(&msg,	//store message here
		m_handle,			//where are we looking for messages (using null will check all messages not just windows ones)
		0,					//min filter, message filters (don't look for some messages)
		0,					//max filter
		PM_REMOVE))			//what to do with messages after read (remove)
	{
		TranslateMessage(&msg);	//for character messages 
		DispatchMessage(&msg);	//send to window Proc
	}

	//check if window was closed
	if (msg.message == WM_NULL)
	{
		if (!IsWindow(m_handle))
		{
			m_handle = NULL;
			UnregisterClass(m_window_class_wide.c_str(), m_hInstance);
			return false;
		}

	}
	return true;

	/// W -- WM_KEYDOWN
/// W -- WM_CHAR
/// W -- WM_KEYUP

}

RenderWindow::~RenderWindow()
{
	///If there is a created window unregister the class and destory the window
	if (m_handle != NULL)
	{
		UnregisterClass(m_window_class_wide.c_str(), m_hInstance);
		DestroyWindow(m_handle);
	}
}

void RenderWindow::RegisterWindowClass()
{
	WNDCLASSEX wc;						//change name
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_window_class_wide.c_str();
	wc.cbSize = sizeof(WNDCLASSEX);	//the size of the struct
	RegisterClassEx(&wc);			//register the class
}

bool ProcessMessages()
{

}

