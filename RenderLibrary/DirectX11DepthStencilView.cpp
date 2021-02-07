#include "DirectX11DepthStencilView.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		DirectX11DepthStencilView::DirectX11DepthStencilView(ComPtr<ID3D11Device> device)
			: device_(device)
		{
		}

		void DirectX11DepthStencilView::Create()
		{
			CreateBuffer();

			CreateDepthStencilView();
		}

		void DirectX11DepthStencilView::CreateBuffer()
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

			HRESULT result = device_->CreateTexture2D(&bufferDescriptor, nullptr, &buffer_);

			ErrorHandler::HandleWindowsError(result, L"Failed to create depth stencil buffer");
		}

		void DirectX11DepthStencilView::CreateDepthStencilView()
		{
			HRESULT result = device_->CreateDepthStencilView(buffer_.Get(), 0, &depthStencilView_);

			ErrorHandler::HandleWindowsError(result, L"Failed to create depth stencil view");
		}

		ComPtr<ID3D11DepthStencilView> DirectX11DepthStencilView::GetView() const
		{
			return depthStencilView_;
		}
	}
}