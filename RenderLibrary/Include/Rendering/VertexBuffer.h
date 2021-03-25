#pragma once

#include <vector>
#include <memory>

#include "Rendering/Vertex.h"

#include "Device.h"
#include "ErrorHandler.h"
#include "Buffer.h"

using namespace DirectX;

namespace RenderLibrary::Rendering
{
	class VertexBuffer : public Buffer
	{
		std::shared_ptr<Device> device_;

	public:
		VertexBuffer(std::shared_ptr<Device> device, const std::vector<Vertex>& vertices);

	private:
		void CreateBuffer(const std::vector<Vertex>& vertices);
		virtual D3D11_BUFFER_DESC CreateBufferDescriptor(size_t bufferSize) const override;

	};
}