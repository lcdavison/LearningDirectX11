#pragma once

#include <vector>
#include <DirectXMath.h>

#include "Vertex.h"
#include "VertexBuffer.h"
#include "Rendering/Drawable.h"

namespace RenderLibrary::Rendering
{
	class StaticMesh : public Drawable
	{
	protected:
		std::shared_ptr<VertexBuffer> vertexBuffer_;

		std::vector<Vertex> vertices;
		std::vector<unsigned long int> indices;

	public:
		StaticMesh(std::shared_ptr<Device> device, const std::vector<Vertex>& vertices);
		StaticMesh(std::shared_ptr<Device> device, std::vector<Vertex>&& vertices);

		void CreateVertexBuffer(std::shared_ptr<Device> device);

		virtual void Render(std::shared_ptr<Device> device) const override;

	};
}