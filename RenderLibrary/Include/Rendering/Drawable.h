#pragma once

#include "Device.h"

#include <memory>

namespace RenderLibrary::Rendering
{
	class Drawable
	{
	public:
		virtual void Render(std::shared_ptr<Device> device) const = 0;
	};
}