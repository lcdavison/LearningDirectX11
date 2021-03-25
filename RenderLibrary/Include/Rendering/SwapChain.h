#pragma once

#include <memory>

namespace RenderLibrary::System
{
	class Window;
}

namespace RenderLibrary::Rendering
{
	class SwapChain
	{
	public:
		virtual void Bind() = 0;

		virtual void Present() = 0;

		virtual void Clear() = 0;

	};
}