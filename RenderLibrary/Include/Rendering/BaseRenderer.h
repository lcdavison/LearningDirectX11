#pragma once

#include <memory>
#include "Module.h"
#include "Window/Window.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		class BaseRenderer : public Module
		{
		protected:
			std::shared_ptr<Window::Window> window_;

		public:
			virtual ~BaseRenderer() = default;

			virtual void Initialise(std::shared_ptr<Window::Window> window) = 0;
			virtual void Render() = 0;

		};
	}
}