#pragma once

#include <Windows.h>

namespace RenderLibrary
{
	namespace Window
	{
		class WindowUpdater
		{
		public:
			WindowUpdater();

			void Update(HWND windowHandle);
		};
	}
}