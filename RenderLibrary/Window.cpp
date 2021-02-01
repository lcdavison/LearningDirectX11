#include "Window.h"

namespace RenderLibrary
{
	namespace Window
	{
		Window::Window(HINSTANCE instance, int showWindow) : Window(instance, showWindow, L"New Window")
		{
		}

		Window::Window(HINSTANCE instance, int showWindow, const std::wstring& windowTitle)
		{
			Create(instance, showWindow, windowTitle);
		}

		Window::~Window()
		{
		}

		void Window::Create(HINSTANCE instance, int showWindow, const std::wstring& windowTitle)
		{
			_windowHandle = _windowCreator.Create(instance, showWindow, windowTitle);
		}

		void Window::Update()
		{
			_windowUpdater.Update(_windowHandle);
		}

		void Window::MakeVisible() const
		{
			ShowWindow(_windowHandle, SW_SHOW);
		}
	}
}