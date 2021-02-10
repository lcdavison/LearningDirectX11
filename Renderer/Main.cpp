#include <Windows.h>

#include <memory>

#include "Game.h"
#include "Window/Window.h"
#include "Exceptions/Exception.h"

#include "Services/ServiceRepository.h"
#include "Services/TestService.h"

using namespace RenderLibrary::Window;
using namespace RenderLibrary::Game;
using namespace RenderLibrary::EventSystem;
using namespace RenderLibrary::Services;

/*
	TODO - Remove window handle from window updater
	TODO - Rename Window class to remove ambiguity
	TODO - Add event data for notification processing
*/

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, INT showCommand)
{
	try
	{
		auto game = std::make_shared<Game> (instance);

		game->Run();

		throw RenderLibrary::Exception(L"Finished");
	}
	catch (RenderLibrary::Exception exception)
	{
		MessageBox(NULL, exception.GetErrorMessage().c_str(), L"Exception Thrown", MB_OK);
	}

	return 0;
}