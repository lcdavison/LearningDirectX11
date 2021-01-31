#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <string>

namespace RenderLibrary
{
	class Window
	{
		HWND _windowHandle;

	public:
		Window(HINSTANCE instance);
		Window(HINSTANCE instance, const std::wstring& title);

		~Window();

	private:
		void Create(HINSTANCE instance, const std::wstring& title);

	private:
		static LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameters, LPARAM lParameters);

	};
}