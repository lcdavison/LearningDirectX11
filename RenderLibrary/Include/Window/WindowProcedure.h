#pragma once

#include <Windows.h>

#include "Services/ServiceRepository.h"
#include "Services/EventDispatcher.h"

namespace RenderLibrary
{
	namespace Window
	{
		static auto GetEventDispatcher()
		{
			return Services::ServiceRepository::GetService<Services::EventDispatcher>(Services::ServiceID::EventDispatcher);
		}

		static LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters)
		{
			switch (message)
			{
			case WM_SIZE:
			{
				auto eventDispatcher = GetEventDispatcher();
				eventDispatcher->PublishToChannel(EventSystem::EventChannel::Window, {});

				break;
			}
			case WM_DESTROY:
			{
				auto eventDispatcher = GetEventDispatcher();
				eventDispatcher->PublishToChannel(EventSystem::EventChannel::Window, {});

				return 0;
			}
			default:
				return DefWindowProc(windowHandle, message, wParameters, lParameters);
			}
		}
	}
}