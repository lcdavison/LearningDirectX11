#pragma once

#include "Renderer.h"
#include "Exception.h"
#include "ErrorHandler.h"
#include "DirectX11RenderTargetView.h"
#include "DirectX11DepthStencilView.h"

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
			ComPtr<ID3D11Device> device_;
			ComPtr<ID3D11DeviceContext> deviceContext_;
			ComPtr<IDXGISwapChain> swapChain_;

			std::shared_ptr<DirectX11RenderTargetView> renderTargetView_;
			std::shared_ptr<DirectX11DepthStencilView> depthStencilView_;

		public:
			DirectX11Renderer();
			virtual ~DirectX11Renderer() override;

			virtual void Initialise(std::shared_ptr<Window::Window> window) override;

			virtual void Start() override;
			virtual void Stop() override;

			virtual void Render() override;

		private:
			void CreateDevice();

			void CreateSwapChain();
			DXGI_SWAP_CHAIN_DESC CreateSwapChainDescriptor();
			ComPtr<IDXGIFactory> GetIDXGIFactory();

			void CreateRenderTargetView();

			void CreateDepthStencilView();

			void SetRenderTargets();

			void SetupViewport();
		};
	}
}