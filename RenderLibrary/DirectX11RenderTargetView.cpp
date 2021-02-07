#include "DirectX11RenderTargetView.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		DirectX11RenderTargetView::DirectX11RenderTargetView(ComPtr<IDXGISwapChain> swapChain)
		{
			GetBackBuffer(swapChain);
		}

		void DirectX11RenderTargetView::GetBackBuffer(ComPtr<IDXGISwapChain> swapChain)
		{
			HRESULT result = swapChain->GetBuffer(0, IID_ID3D11Texture2D, &backBuffer_);

			ErrorHandler::HandleWindowsError(result, L"Failed to retrieve back buffer");
		}

		void DirectX11RenderTargetView::Create(ComPtr<ID3D11Device> device)
		{
			HRESULT result = device->CreateRenderTargetView(backBuffer_.Get(), NULL, &renderTargetView_);

			ErrorHandler::HandleWindowsError(result, L"Failed to create render target view");
		}
	}
}