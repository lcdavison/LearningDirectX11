#include <Windows.h>

#include "Game.h"
#include "Window/Window.h"
#include "Exceptions/Exception.h"
#include "ApplicationState.h"

using namespace RenderLibrary::Window;
using namespace RenderLibrary::Game;

/*
	TODO - Make renderer responsible for window
	TODO - Rename Window class to remove ambiguity
*/

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, INT showCommand)
{
	try
	{
		Game game (instance);
		game.Run();
	}
	catch (RenderLibrary::Exception exception)
	{
		MessageBox(NULL, exception.GetErrorMessage().c_str(), L"Fatal Error", MB_OK);
	}

	return 0;
}