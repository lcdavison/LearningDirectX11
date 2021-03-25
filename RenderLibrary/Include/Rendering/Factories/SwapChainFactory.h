#pragma once

#include <memory>

namespace RenderLibrary::Rendering
{
	class SwapChain;
}

namespace RenderLibrary::System
{
	class Window;
}

namespace RenderLibrary::Rendering::Factory
{
	class SwapChainFactory
	{
	public:
		virtual std::shared_ptr<Rendering::SwapChain> CreateSwapChain(std::shared_ptr<System::Window> window) = 0;

	};
}