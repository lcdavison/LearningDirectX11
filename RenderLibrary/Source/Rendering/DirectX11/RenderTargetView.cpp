#include "Rendering/DirectX11/RenderTargetView.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			RenderTargetView::RenderTargetView(std::shared_ptr<Device> device, ComPtr<IDXGISwapChain> swapChain)
				: device_(device)
			{
				GetBackBuffer(swapChain);
			}

			void RenderTargetView::GetBackBuffer(ComPtr<IDXGISwapChain> swapChain)
			{
				HRESULT result = swapChain->GetBuffer(0, IID_ID3D11Texture2D, &backBuffer_);

				ErrorHandler::HandleWindowsError(result, L"Failed to retrieve back buffer");
			}

			void RenderTargetView::Create()
			{
				auto device = device_->GetDeviceInterface();

				HRESULT result = device->CreateRenderTargetView(backBuffer_.Get(), NULL, &renderTargetView_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create render target view");
			}

			ComPtr<ID3D11RenderTargetView> RenderTargetView::GetView() const
			{
				return renderTargetView_;
			}
		}
	}
}