#pragma once

#include <windows.h>

#include <string>

namespace RenderLibrary
{
	class Window
	{
		HWND _windowHandle;

	public:
		Window(HINSTANCE instance, int showWindow);
		Window(HINSTANCE instance, int showWindow, const std::wstring& title);

		~Window();

		void Update();

	private:
		void Create(HINSTANCE instance, int showWindow, const std::wstring& title);

	private:
		static LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters);

	};
}