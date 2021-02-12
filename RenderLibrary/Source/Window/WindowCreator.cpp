#include "Window/WindowCreator.h"
#include "Window/WindowProcedure.h"

namespace RenderLibrary
{
	namespace Window
	{
		WindowCreator::WindowCreator()
		{
		}

		HWND WindowCreator::Create(HINSTANCE instance, const std::wstring& windowTitle) const
		{
			const wchar_t className [] = L"Render Window Class";

			CreateAndRegisterWindowClass(className, instance);

			HWND windowHandle = CreateWindowEx(0, className, windowTitle.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, NULL, NULL, instance, NULL);

			if (windowHandle == NULL)
			{
				throw Exception(L"Failed to create window: " + windowTitle);
			}

			return windowHandle;
		}

		void WindowCreator::CreateAndRegisterWindowClass(const std::wstring& className, HINSTANCE instance) const
		{
			WNDCLASS windowClass {};
			windowClass.lpfnWndProc = RenderLibrary::Window::WindowProcedure;
			windowClass.hInstance = instance;
			windowClass.lpszClassName = className.c_str();

			RegisterClass(&windowClass);
		}
	}	
}