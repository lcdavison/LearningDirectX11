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
			HWND windowHandle_;

			WindowCreator windowCreator_;
			WindowUpdater windowUpdater_;

		public:
			Window(HINSTANCE instance);
			Window(HINSTANCE instance, const std::wstring& windowTitle);

			~Window();

			void Update();

			void MakeVisible() const;

			HWND GetWindowHandle() const;

		private:
			void Create(HINSTANCE instance, const std::wstring& windowTitle);

		};
	}
}