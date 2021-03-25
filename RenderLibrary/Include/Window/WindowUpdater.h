#pragma once

#include <Windows.h>

namespace RenderLibrary::System
{
	class WindowUpdater
	{
	public:
		WindowUpdater();

		void Update(HWND windowHandle);
	};
}