#include "Window.h"

#include <iostream>

#include "Exception.h"

namespace RenderLibrary
{
	Window::Window(HINSTANCE instance, int showWindow) : Window(instance, showWindow, L"New Window")
	{
	}

	Window::Window(HINSTANCE instance, int showWindow, const std::wstring& title)
	{
		Create(instance, showWindow, title);
	}

	Window::~Window()
	{
	}

	void Window::Create(HINSTANCE instance, int showWindow, const std::wstring& title)
	{
		const wchar_t className [] = L"Render Window Class";

		WNDCLASS windowClass {};

		windowClass.lpfnWndProc = Window::WindowProcedure;
		windowClass.hInstance = instance;
		windowClass.lpszClassName = className;

		RegisterClass(&windowClass);

		_windowHandle = CreateWindowEx(0, className, title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, NULL, NULL, instance, NULL);

		if (_windowHandle == NULL)
		{
			throw Exception(L"Failed to create window");
		}

		ShowWindow(_windowHandle, showWindow);
	}

	void Window::Update()
	{
		MSG message {};

		while (GetMessage(&message, _windowHandle, 0, 0))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	LRESULT CALLBACK Window::WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters)
	{
		return DefWindowProc(windowHandle, message, wParameters, lParameters);
	}
}