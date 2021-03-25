#pragma once

#include "Rendering/SwapChain.h"
#include "Rendering/DirectX11/DX11Device.h"
#include "Window/Window.h"

#include <wrl.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <memory>

namespace RenderLibrary::Rendering::DirectX11
{
	class DX11SwapChain : public Rendering::SwapChain
	{
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface_;
		Microsoft::WRL::ComPtr<IDXGISwapChain> swapChainInterface_;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView_;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer_;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView_;

	public:
		DX11SwapChain() = delete;

		DX11SwapChain(Microsoft::WRL::ComPtr<ID3D11DeviceContext> contextInterface,
					  Microsoft::WRL::ComPtr<IDXGISwapChain> swapChainInterface,
					  Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView,
					  Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView,
					  Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer);

		virtual void Bind() override;

		virtual void Present() override;

		virtual void Clear() override;

	};
}