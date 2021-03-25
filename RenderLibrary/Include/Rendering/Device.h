#pragma once

#include <memory>
#include <wrl.h>

namespace RenderLibrary::System
{
	class Window;
}

namespace RenderLibrary::Rendering::Factory
{
	class SwapChainFactory;
}

namespace RenderLibrary::Rendering
{
	class VertexBuffer;
	class SwapChain;

	class Device
	{
	protected:
		std::unique_ptr<Factory::SwapChainFactory> swapChainFactory_;

	public:
		virtual std::shared_ptr<SwapChain> CreateSwapChain(std::shared_ptr<System::Window> window) = 0;

		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer() = 0;
	};
}