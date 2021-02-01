#pragma once

#include "WindowCreator.h"
#include "WindowUpdater.h"

#include <string>

namespace RenderLibrary
{
	namespace Window
	{
		class Window
		{
			HWND _windowHandle;

			WindowCreator _windowCreator;
			WindowUpdater _windowUpdater;

		public:
			Window(HINSTANCE instance, int showWindow);
			Window(HINSTANCE instance, int showWindow, const std::wstring& windowTitle);

			~Window();

			void Update();

			void MakeVisible() const;

		private:
			void Create(HINSTANCE instance, int showWindow, const std::wstring& windowTitle);

		};
	}
}