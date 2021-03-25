#include "Rendering/Factories/DX11BufferFactory.h"

using namespace RenderLibrary::Rendering;
using namespace RenderLibrary::Rendering::DirectX11;
using namespace Microsoft::WRL;

namespace RenderLibrary::Rendering::Factory
{
	DX11BufferFactory::DX11BufferFactory(ComPtr<ID3D11Device> deviceInterface,
										 ComPtr<ID3D11DeviceContext> contextInterface)
		: deviceInterface_ {deviceInterface},
		contextInterface_ {contextInterface}
	{
	}

	std::shared_ptr<VertexBuffer> DX11BufferFactory::CreateVertexBuffer(std::vector<Vertex> vertices)
	{
		ComPtr<ID3D11Buffer> vertexBufferInterface {};

		auto vertexBufferDescriptor = CreateVertexBufferDescriptor(sizeof(Vertex) * vertices.size());

		D3D11_SUBRESOURCE_DATA vertexData {};
		vertexData.pSysMem = vertices.data();

		auto result = deviceInterface_->CreateBuffer(&vertexBufferDescriptor, &vertexData, &vertexBufferInterface);

		ErrorHandler::HandleWindowsError(result, L"Failed to create Vertex Buffer");

		return std::make_shared<DX11VertexBuffer>(contextInterface_, vertexBufferInterface);
	}

	D3D11_BUFFER_DESC DX11BufferFactory::CreateVertexBufferDescriptor(size_t bufferSize)
	{
		D3D11_BUFFER_DESC vertexBufferDescriptor {};

		vertexBufferDescriptor.ByteWidth = bufferSize;
		vertexBufferDescriptor.Usage = D3D11_USAGE_IMMUTABLE;
		vertexBufferDescriptor.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDescriptor.StructureByteStride = 0;
		vertexBufferDescriptor.BindFlags = 0;
		vertexBufferDescriptor.CPUAccessFlags = 0;

		return vertexBufferDescriptor;
	}
}