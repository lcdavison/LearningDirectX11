#include "Rendering/DirectX11/DepthStencilView.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			DepthStencilView::DepthStencilView(std::shared_ptr<Device> device)
				: device_(device)
			{
			}

			void DepthStencilView::Create()
			{
				CreateBuffer();

				CreateDepthStencilView();
			}

			void DepthStencilView::CreateBuffer()
			{
				D3D11_TEXTURE2D_DESC bufferDescriptor {};

				bufferDescriptor.Width = 1280;
				bufferDescriptor.Height = 720;

				bufferDescriptor.MipLevels = 1;

				bufferDescriptor.ArraySize = 1;

				bufferDescriptor.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

				bufferDescriptor.SampleDesc.Count = 1;
				bufferDescriptor.SampleDesc.Quality = 0;

				bufferDescriptor.Usage = D3D11_USAGE_DEFAULT;

				bufferDescriptor.BindFlags = D3D11_BIND_DEPTH_STENCIL;

				bufferDescriptor.CPUAccessFlags = 0;
				bufferDescriptor.MiscFlags = 0;

				auto device = device_->GetDeviceInterface();

				HRESULT result = device->CreateTexture2D(&bufferDescriptor, nullptr, &buffer_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create depth stencil buffer");
			}

			void DepthStencilView::CreateDepthStencilView()
			{
				auto device = device_->GetDeviceInterface();

				HRESULT result = device->CreateDepthStencilView(buffer_.Get(), 0, &depthStencilView_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create depth stencil view");
			}

			ComPtr<ID3D11DepthStencilView> DepthStencilView::GetView() const
			{
				return depthStencilView_;
			}
		}
	}
}