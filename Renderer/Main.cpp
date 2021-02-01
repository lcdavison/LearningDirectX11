#include <Windows.h>

#include "Game.h"
#include "Window.h"
#include "Exception.h"

using namespace RenderLibrary::Window;
using namespace RenderLibrary::Game;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int showCommand)
{
	try
	{
		Window window(instance, showCommand);

		window.MakeVisible();
	}
	catch (RenderLibrary::Exception exception)
	{
		MessageBox(NULL, exception.GetErrorMessage().c_str(), L"Fatal Error", MB_OK);
	}

	return 0;
}