#include "Window/Window.h"

namespace RenderLibrary::System
{
	Window::Window(HINSTANCE instance) : Window(instance, L"New Window")
	{
	}

	Window::Window(HINSTANCE instance, const std::wstring& windowTitle)
		: instance_(instance),
		windowTitle_(windowTitle)
	{
	}

	Window::~Window()
	{
	}

	void Window::Start()
	{
		Create();

		MakeVisible();
	}

	void Window::Stop()
	{

	}

	void Window::Create()
	{
		windowHandle_ = windowCreator_.Create(instance_, windowTitle_);
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