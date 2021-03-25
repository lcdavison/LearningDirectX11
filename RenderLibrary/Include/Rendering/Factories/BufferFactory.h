#pragma once

#include "Rendering/Vertex.h"

#include <memory>
#include <vector>

namespace RenderLibrary::Rendering
{
	class VertexBuffer;
}

namespace RenderLibrary::Rendering::Factory
{
	class BufferFactory
	{
	public:
		virtual std::shared_ptr<Rendering::VertexBuffer> CreateVertexBuffer(const std::vector<Rendering::Vertex> vertices) = 0;

	};
}