#pragma once

#include "Renderer.h"
#include "Exception.h"
#include "ErrorHandler.h"

#include <wrl.h>
#include <d3d11.h>
#include <memory>

using namespace Microsoft::WRL;

namespace RenderLibrary
{
	namespace Rendering
	{
		class DirectX11Renderer : public Renderer
		{
			ComPtr<ID3D11Device> _device;
			ComPtr<ID3D11DeviceContext> _deviceContext;
			ComPtr<IDXGISwapChain> _swapChain;

		public:
			DirectX11Renderer();

			virtual void Start() override;
			virtual void Stop() override;

			virtual void Render() override;

		private:
			void CreateDevice();

			void CreateSwapChain();
			DXGI_SWAP_CHAIN_DESC CreateSwapChainDescriptor();
		};
	}
}