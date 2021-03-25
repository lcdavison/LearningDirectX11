#pragma once

#include "SwapChainFactory.h"
#include "Rendering/DirectX11/DX11SwapChain.h"
#include "Window/Window.h"
#include "ErrorHandler.h"

#include <wrl.h>
#include <d3d11.h>
#include <memory>

namespace RenderLibrary::Rendering::Factory
{
	class DX11SwapChainFactory : public SwapChainFactory
	{
		Microsoft::WRL::ComPtr<ID3D11Device> deviceInterface_;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface_;

	public:
		DX11SwapChainFactory(Microsoft::WRL::ComPtr<ID3D11Device> deviceInterface,
							 Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface);

		virtual std::shared_ptr<Rendering::SwapChain> CreateSwapChain(std::shared_ptr<System::Window> window) override;

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> CreateDXGISwapChain(std::shared_ptr<System::Window> window);
		DXGI_SWAP_CHAIN_DESC CreateSwapChainDescriptor(std::shared_ptr<System::Window> window);
		DXGI_SAMPLE_DESC GetMultiSamplingDescriptor(int sampleCount) const;
		Microsoft::WRL::ComPtr<IDXGIFactory> GetIDXGIFactory() const;

		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> CreateRenderTargetView(Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer);

		Microsoft::WRL::ComPtr<ID3D11Texture2D> CreateDepthStencilBuffer();
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> CreateDepthStencilView(Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer);
		D3D11_TEXTURE2D_DESC CreateDepthStencilBufferDescriptor();
	};
}