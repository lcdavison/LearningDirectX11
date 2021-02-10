#pragma once

#include <Windows.h>

#include <string>
#include "Exceptions/Exception.h"

namespace RenderLibrary
{
	namespace Window
	{
		class WindowCreator
		{
		public:
			WindowCreator();

			HWND Create(HINSTANCE instance, const std::wstring& windowTitle) const;

		private:

			void CreateAndRegisterWindowClass(const std::wstring& className, HINSTANCE instance) const;
		};
	}
}