#pragma once

#include <wrl.h>
#include <d3d11.h>
#include <memory>

#include "ErrorHandler.h"
#include "Rendering/DirectX11/Device.h"
#include "Rendering/DirectX11/SwapChain.h"

using namespace Microsoft::WRL;

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			class RenderTargetView
			{
				std::shared_ptr<Device> device_;
				std::shared_ptr<SwapChain> swapChain_;

				ComPtr<ID3D11RenderTargetView> renderTargetViewInterface_;

			public:
				RenderTargetView(std::shared_ptr<Device> device, std::shared_ptr<SwapChain> swapChain);

				void Create();

				ComPtr<ID3D11RenderTargetView> GetViewInterface() const;
			};
		}
	}
}