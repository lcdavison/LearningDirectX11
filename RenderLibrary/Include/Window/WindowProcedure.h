#pragma once

#include <Windows.h>

#include "EventSystem/Events/WindowEvent.h"
#include "EventSystem/EventRegistry.h"

#include "Services/ServiceRepository.h"
#include "Services/EventDispatcher.h"

namespace RenderLibrary
{
	namespace Window
	{
		static auto GetEventDispatcher()
		{
			using namespace RenderLibrary::Services;

			return ServiceRepository::GetService<EventDispatcher>(ServiceID::EventDispatcher);
		}

		static void PublishWindowEvent(const EventSystem::WindowEvent& windowEvent)
		{
			using namespace RenderLibrary::EventSystem;

			auto eventDispatcher = GetEventDispatcher();

			auto windowEventPointer = std::make_shared<WindowEvent>(windowEvent);
			eventDispatcher->PublishEvent(windowEventPointer);
		}

		static LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters)
		{
			switch (message)
			{
			case WM_SIZE:
			{
				auto width = LOWORD(lParameters);
				auto height = HIWORD(lParameters);

				using namespace EventSystem;
				auto windowEvent = EventRegistry::CloneEvent<WindowEvent>();

				windowEvent.HasWindowClosed = false;
				windowEvent.NewWidth = width;
				windowEvent.NewHeight = height;

				PublishWindowEvent({false, width, height});

				break;
			}
			case WM_DESTROY:
			{
				using namespace EventSystem;
				auto windowEvent = EventRegistry::CloneEvent<WindowEvent>();

				windowEvent.HasWindowClosed = true;

				PublishWindowEvent(windowEvent);

				return 0;
			}
			default:
				return DefWindowProc(windowHandle, message, wParameters, lParameters);
			}
		}
	}
}