#include "Rendering/DirectX11/DX11SwapChain.h"

using namespace Microsoft::WRL;

namespace RenderLibrary::Rendering::DirectX11
{
	DX11SwapChain::DX11SwapChain(ComPtr<ID3D11DeviceContext> contextInterface,
								 ComPtr<IDXGISwapChain> swapChainInterface,
								 ComPtr<ID3D11RenderTargetView> renderTargetView,
								 ComPtr<ID3D11DepthStencilView> depthStencilView,
								 ComPtr<ID3D11Texture2D> depthStencilBuffer)
		: contextInterface_ {contextInterface},
		swapChainInterface_ {swapChainInterface},
		renderTargetView_ {renderTargetView},
		depthStencilView_ {depthStencilView}
	{
	}

	void DX11SwapChain::Bind()
	{
		auto renderTargets = renderTargetView_.Get();
		contextInterface_->OMSetRenderTargets(1, &renderTargets, depthStencilView_.Get());

		D3D11_VIEWPORT viewport {};

		viewport.Width = 1280;
		viewport.Height = 720;

		viewport.MaxDepth = 1.0f;
		viewport.MinDepth = 0.0f;

		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		contextInterface_->RSSetViewports(1, &viewport);
	}

	void DX11SwapChain::Present()
	{
		auto result = swapChainInterface_->Present(0, 0);
	}

	void DX11SwapChain::Clear()
	{
		DirectX::XMFLOAT4 clearColour {0.0f, 1.0f, 0.0f, 1.0f};
		contextInterface_->ClearRenderTargetView(renderTargetView_.Get(), reinterpret_cast<float*>(&clearColour));

		contextInterface_->ClearDepthStencilView(depthStencilView_.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	}
}