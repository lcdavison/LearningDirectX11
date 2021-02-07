#include "Window.h"

namespace RenderLibrary
{
	namespace Window
	{
		Window::Window(HINSTANCE instance) : Window(instance, L"New Window")
		{
		}

		Window::Window(HINSTANCE instance, const std::wstring& windowTitle)
		{
			Create(instance, windowTitle);
		}

		Window::~Window()
		{
		}

		void Window::Create(HINSTANCE instance, const std::wstring& windowTitle)
		{
			windowHandle_ = windowCreator_.Create(instance, windowTitle);
		}

		void Window::Update()
		{
			windowUpdater_.Update(windowHandle_);
		}

		void Window::MakeVisible() const
		{
			ShowWindow(windowHandle_, SW_SHOW);
		}

		HWND Window::GetWindowHandle() const
		{
			return windowHandle_;
		}
	}
}