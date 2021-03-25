#pragma once

#include "Rendering/Device.h"
#include "Rendering/Factories/Dx11SwapChainFactory.h"
#include "Rendering/Factories/DX11BufferFactory.h"
#include "Window/Window.h"
#include "ErrorHandler.h"

#include <wrl.h>
#include <d3d11.h>

namespace RenderLibrary::Rendering::DirectX11
{
	class DX11Device : public Device
	{
		Microsoft::WRL::ComPtr<ID3D11Device> deviceInterface_;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface_;

	public:
		DX11Device();

		virtual std::shared_ptr<Rendering::SwapChain> CreateSwapChain(std::shared_ptr<System::Window> window) override;

		virtual std::shared_ptr<Rendering::VertexBuffer> CreateVertexBuffer(const std::vector<Vertex>& vertices) override;
	};
}