#include "Engine.h"



bool Engine::Initilize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	//windows container pointer is this since engine inherits from window container
	return render_window.Initilize(this, hInstance, window_title, window_class, width, height);

	//initilize graphics
}
bool Engine::ProcessMessages()
{
	return render_window.ProcessMessages();
}
Engine::Engine()
{
}


Engine::~Engine()
{
}
