#pragma once

#include "Window/Window.h"
#include "Rendering/Device.h"
#include "Rendering/SwapChain.h"

#include <memory>

namespace RenderLibrary::Rendering
{
	class GraphicsContext
	{
		std::shared_ptr<Device> device_;
		std::shared_ptr<SwapChain> swapChain_;
		std::shared_ptr<System::Window> window_;

	public:
		GraphicsContext(std::shared_ptr<Device> device, std::shared_ptr<System::Window> window);
		GraphicsContext(const GraphicsContext& graphicsContext) = delete;
		GraphicsContext(GraphicsContext&& graphicsContext) = delete;

		void Draw();
		void Clear();

		std::shared_ptr<Device> GetDevice() const;
	};
}