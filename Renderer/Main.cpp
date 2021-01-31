#include <Windows.h>

#include "Window.h"
#include "Exception.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int showCommand)
{
	try
	{
		RenderLibrary::Window window(instance, showCommand);
	}
	catch (RenderLibrary::Exception exception)
	{
		MessageBox(NULL, exception.Message().c_str(), L"Fatal Error", MB_OK);
	}

	return 0;
}