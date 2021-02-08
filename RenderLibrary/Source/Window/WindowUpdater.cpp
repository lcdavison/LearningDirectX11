#include "Window/WindowUpdater.h"

namespace RenderLibrary
{
	namespace Window
	{
		WindowUpdater::WindowUpdater()
		{
		}

		void WindowUpdater::Update(HWND windowHandle)
		{
			MSG message {};

			while (PeekMessage(&message, windowHandle, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
	}	
}