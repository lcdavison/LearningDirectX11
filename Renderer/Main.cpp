#include <Windows.h>

#include "Game.h"
#include "Window.h"
#include "Exception.h"
#include "ApplicationState.h"

using namespace RenderLibrary::Window;
using namespace RenderLibrary::Game;

/*
	TODO - Make renderer responsible for window
	TODO - Pass a startup info struct to game, to remove global state
*/

static void SetApplicationState(HINSTANCE instance, INT showCommand)
{
	RenderLibrary::ApplicationState::instance = instance;
	RenderLibrary::ApplicationState::showCommand = showCommand;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, INT showCommand)
{
	SetApplicationState(instance, showCommand);

	try
	{
		Game game;
		game.Run();
	}
	catch (RenderLibrary::Exception exception)
	{
		MessageBox(NULL, exception.GetErrorMessage().c_str(), L"Fatal Error", MB_OK);
	}

	return 0;
}