#pragma once

#include <Windows.h>

#include "EventSystem/WindowEvent.h"

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

		static void PublishWindowEvent(EventSystem::WindowEvent&& windowEvent)
		{
			using namespace RenderLibrary::EventSystem;

			auto eventDispatcher = GetEventDispatcher();

			auto windowEventPointer = std::make_shared<WindowEvent>(windowEvent);
			eventDispatcher->PublishToChannel(EventChannel::Window, windowEventPointer);
		}

		static LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters)
		{
			switch (message)
			{
			case WM_SIZE:
			{
				auto width = LOWORD(lParameters);
				auto height = HIWORD(lParameters);

				PublishWindowEvent({false, width, height});

				break;
			}
			case WM_DESTROY:
			{
				PublishWindowEvent({true, 0, 0});

				return 0;
			}
			default:
				return DefWindowProc(windowHandle, message, wParameters, lParameters);
			}
		}
	}
}