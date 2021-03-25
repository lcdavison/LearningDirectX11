#pragma once

#include "Vertex.h"

#include <memory>
#include <vector>
#include <wrl.h>

namespace RenderLibrary::System
{
	class Window;
}

namespace RenderLibrary::Rendering::Factory
{
	class SwapChainFactory;
	class BufferFactory;
}

namespace RenderLibrary::Rendering
{
	class VertexBuffer;
	class SwapChain;

	class Device
	{
	protected:
		std::unique_ptr<Factory::SwapChainFactory> swapChainFactory_;
		std::unique_ptr<Factory::BufferFactory> bufferFactory_;

	public:
		virtual std::shared_ptr<SwapChain> CreateSwapChain(std::shared_ptr<System::Window> window) = 0;

		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(const std::vector<Vertex>& vertices) = 0;
	};
}