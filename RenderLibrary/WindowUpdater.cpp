#include "WindowUpdater.h"

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

			while (GetMessage(&message, windowHandle, 0, 0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
	}	
}