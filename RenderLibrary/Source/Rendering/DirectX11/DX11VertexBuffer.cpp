#include "Rendering/DirectX11/DX11VertexBuffer.h"

using namespace RenderLibrary::Rendering;
using namespace Microsoft::WRL;

namespace RenderLibrary::Rendering::DirectX11
{
	DX11VertexBuffer::DX11VertexBuffer(ComPtr<ID3D11DeviceContext> contextInterface,
									   ComPtr<ID3D11Buffer> vertexBufferInterface)
		: contextInterface_ {contextInterface},
		vertexBufferInterface_ {vertexBufferInterface}
	{
	}

	void DX11VertexBuffer::Bind()
	{
		auto stride = static_cast<unsigned int>(sizeof(Vertex));
		auto offset = 0u;

		contextInterface_->IASetVertexBuffers(0, 1, &vertexBufferInterface_, &stride, &offset);
	}
}