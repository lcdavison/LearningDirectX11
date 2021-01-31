#include "Window.h"

#include <iostream>

namespace RenderLibrary
{
	Window::Window(HINSTANCE instance) : Window(instance, L"New Window")
	{
	}

	Window::Window(HINSTANCE instance, const std::wstring& title)
	{
		Create(instance, title);
	}

	Window::~Window()
	{
	}

	void Window::Create(HINSTANCE instance, const std::wstring& title)
	{
		const wchar_t className [] = L"Render Window Class";

		WNDCLASS windowClass {};

		windowClass.lpfnWndProc = Window::WindowProcedure;
		windowClass.hInstance = instance;
		windowClass.lpszClassName = className;

		_windowHandle = CreateWindowEx(0, className, title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, NULL, NULL, instance, NULL);

		if (_windowHandle == NULL)
		{
			throw std::exception("Failed to create window");
		}
	}

	LRESULT CALLBACK Window::WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters)
	{
		return DefWindowProc(windowHandle, message, wParameters, lParameters);
	}
}