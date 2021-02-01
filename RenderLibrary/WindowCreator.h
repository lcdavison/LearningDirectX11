#pragma once

#include <Windows.h>

#include <string>
#include "Exception.h"

namespace RenderLibrary
{
	namespace Window
	{
		static LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters);

		class WindowCreator
		{
		public:
			WindowCreator();

			HWND Create(HINSTANCE instance, int showCommand, const std::wstring& windowTitle) const;

		private:

			void CreateAndRegisterWindowClass(const std::wstring& className, HINSTANCE instance) const;
		};
	}
}