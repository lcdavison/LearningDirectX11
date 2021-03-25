#pragma once

#include "WindowCreator.h"
#include "WindowUpdater.h"
#include "Module.h"

#include <string>

namespace RenderLibrary::System
{
	class Window : public Module
	{
		HWND windowHandle_;
		HINSTANCE instance_;
		std::wstring windowTitle_;

		WindowCreator windowCreator_;
		WindowUpdater windowUpdater_;

	public:
		Window(HINSTANCE instance);
		Window(HINSTANCE instance, const std::wstring& windowTitle);

		~Window();

		virtual void Start() override;
		virtual void Stop() override;

		void Update();

		HWND GetWindowHandle() const;

	private:
		void Create();

		void MakeVisible() const;
	};
}