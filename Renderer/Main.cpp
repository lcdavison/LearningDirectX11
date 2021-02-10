#include <Windows.h>

#include <memory>

#include "Game.h"
#include "Window/Window.h"
#include "Exceptions/Exception.h"
#include "ApplicationState.h"
#include "EventSystem/EventDispatcher.h"

#include "Services/ServiceRepository.h"
#include "Services/TestService.h"

using namespace RenderLibrary::Window;
using namespace RenderLibrary::Game;
using namespace RenderLibrary::EventSystem;
using namespace RenderLibrary::Services;

/*
	TODO - Make renderer responsible for window
	TODO - Rename Window class to remove ambiguity
*/

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, INT showCommand)
{
	try
	{
		auto game = std::make_shared<Game> (instance);

		game->Run();
	}
	catch (RenderLibrary::Exception exception)
	{
		MessageBox(NULL, exception.GetErrorMessage().c_str(), L"Fatal Error", MB_OK);
	}

	return 0;
}