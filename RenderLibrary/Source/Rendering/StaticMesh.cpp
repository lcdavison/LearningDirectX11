#include "Rendering/StaticMesh.h"

namespace RenderLibrary::Rendering
{
	StaticMesh::StaticMesh(std::shared_ptr<Device> device, const std::vector<Vertex>& vertices)
		: vertices {vertices}, 
		indices {}
	{
		vertexBuffer_ = std::make_shared<VertexBuffer>(device, vertices);
	}

	StaticMesh::StaticMesh(std::shared_ptr<Device> device, std::vector<Vertex>&& vertices)
		: vertices {vertices},
		indices {}
	{
		vertexBuffer_ = std::make_shared<VertexBuffer>(device, vertices);
	}

	void StaticMesh::CreateVertexBuffer(std::shared_ptr<Device> device)
	{
		vertexBuffer_ = std::make_shared<VertexBuffer>(device, vertices);
	}

	void StaticMesh::Render(std::shared_ptr<Device> device) const
	{

	}
}