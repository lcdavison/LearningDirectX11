#include "Rendering/DirectX11/DX11Device.h"

using namespace RenderLibrary::System;
using namespace RenderLibrary::Rendering::Factory;
using namespace Microsoft::WRL;

namespace RenderLibrary::Rendering::DirectX11
{
	DX11Device::DX11Device()
	{
		UINT flags {};

		D3D_FEATURE_LEVEL featureLevel {};
		D3D_FEATURE_LEVEL featureLevels [] { D3D_FEATURE_LEVEL_11_0 };

		HRESULT result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, featureLevels, 1, D3D11_SDK_VERSION, &deviceInterface_, &featureLevel, &contextInterface_);

		ErrorHandler::HandleWindowsError(result, L"Failed to create DirectX 11 device");

		if (featureLevel != D3D_FEATURE_LEVEL_11_0)
		{
			throw Exception(L"DirectX 11 not supported");
		}

		swapChainFactory_ = std::make_unique<DX11SwapChainFactory>(deviceInterface_, contextInterface_);
	}

	std::shared_ptr<Rendering::SwapChain> DX11Device::CreateSwapChain(std::shared_ptr<Window> window)
	{
		return swapChainFactory_->CreateSwapChain(window);
	}

	std::shared_ptr<Rendering::VertexBuffer> DX11Device::CreateVertexBuffer()
	{
		return nullptr;
	}
}