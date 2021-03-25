#pragma once

#include <memory>
#include "Module.h"
#include "Window/Window.h"

using namespace RenderLibrary::System;

namespace RenderLibrary::Rendering
{
	class BaseRenderer : public Module
	{
	protected:
		std::shared_ptr<Window> window_;

	public:
		virtual ~BaseRenderer() = default;

		virtual void Initialise(std::shared_ptr<Window> window) = 0;
		virtual void Render() = 0;

	};
}