#pragma once

#include "BufferFactory.h"
#include "Rendering/DirectX11/DX11VertexBuffer.h"

#include "ErrorHandler.h"

#include <wrl.h>
#include <d3d11.h>

namespace RenderLibrary::Rendering::Factory
{
	class DX11BufferFactory : public BufferFactory
	{
		Microsoft::WRL::ComPtr<ID3D11Device> deviceInterface_;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface_;

	public:
		DX11BufferFactory(Microsoft::WRL::ComPtr<ID3D11Device> deviceInterface,
						  Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface);

		virtual std::shared_ptr<Rendering::VertexBuffer> CreateVertexBuffer(const std::vector<Rendering::Vertex> vertices) override;
		D3D11_BUFFER_DESC CreateVertexBufferDescriptor(size_t bufferSize);

	};
}