#pragma once

#include "Rendering/VertexBuffer.h"
#include "Rendering/Vertex.h"

#include <wrl.h>
#include <d3d11.h>

namespace RenderLibrary::Rendering::DirectX11
{
	class DX11VertexBuffer : public VertexBuffer
	{
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface_;
		Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBufferInterface_;

	public:
		DX11VertexBuffer(Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface,
						 Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBufferInterface);

		virtual void Bind() override;

	};
}