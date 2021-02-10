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

			while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_QUIT)
					break;

				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
	}
}