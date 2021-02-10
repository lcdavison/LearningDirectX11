#include "Rendering/DirectX11/RenderTargetView.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			RenderTargetView::RenderTargetView(std::shared_ptr<Device> device, std::shared_ptr<SwapChain> swapChain)
				: device_(device),
				swapChain_(swapChain)
			{
			}

			void RenderTargetView::Create()
			{
				auto device = device_->GetDeviceInterface();

				auto backBuffer = swapChain_->GetBackBuffer();

				HRESULT result = device->CreateRenderTargetView(backBuffer.Get(), NULL, &renderTargetViewInterface_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create render target view");
			}

			ComPtr<ID3D11RenderTargetView> RenderTargetView::GetViewInterface() const
			{
				return renderTargetViewInterface_;
			}
		}
	}
}