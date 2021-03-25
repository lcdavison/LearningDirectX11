#include "Rendering/StaticMesh.h"

namespace RenderLibrary::Rendering
{
	StaticMesh::StaticMesh(std::shared_ptr<Device> device, const std::vector<Vertex>& vertices)
		: vertices {vertices}, 
		indices {}
	{
	}

	StaticMesh::StaticMesh(std::shared_ptr<Device> device, std::vector<Vertex>&& vertices)
		: vertices {vertices},
		indices {}
	{
	}

	void StaticMesh::Render(std::shared_ptr<Device> device) const
	{

	}
}