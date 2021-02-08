#pragma once

#include <wrl.h>
#include <d3d11.h>
#include <memory>

#include "Window/Window.h"
#include "Rendering/DirectX11/Device.h"

using namespace Microsoft::WRL;

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			class SwapChain
			{
				std::shared_ptr<Device> device_;
				std::shared_ptr<Window::Window> window_;

				ComPtr<IDXGISwapChain> swapChain_;

			public:
				SwapChain(std::shared_ptr<Device> device, std::shared_ptr<Window::Window> window);

				void Create();

				void PresentBackBuffer() const;

				ComPtr<ID3D11Texture2D> GetBackBuffer() const;

			private:
				DXGI_SWAP_CHAIN_DESC CreateSwapChainDescriptor() const;

				ComPtr<IDXGIFactory> GetIDXGIFactory() const;
			};
		}
	}
}