#include "Rendering/DirectX11/SwapChain.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			SwapChain::SwapChain(std::shared_ptr<Device> device, std::shared_ptr<Window::Window> window)
				: device_(device),
				window_(window)
			{
			}

			void SwapChain::Create()
			{
				auto device = device_->GetDeviceInterface();
				
				swapChain_.Reset();

				DXGI_SWAP_CHAIN_DESC swapChainDescriptor = CreateSwapChainDescriptor();

				auto idxgiFactory = GetIDXGIFactory();
				HRESULT result = idxgiFactory->CreateSwapChain(device.Get(), &swapChainDescriptor, &swapChain_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create swap chain");
			}

			DXGI_SWAP_CHAIN_DESC SwapChain::CreateSwapChainDescriptor() const
			{
				DXGI_SWAP_CHAIN_DESC swapChainDescriptor {};

				swapChainDescriptor.BufferDesc.Width = 1280;
				swapChainDescriptor.BufferDesc.Height = 720;
				swapChainDescriptor.BufferDesc.RefreshRate.Numerator = 60;
				swapChainDescriptor.BufferDesc.RefreshRate.Denominator = 1;
				swapChainDescriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				swapChainDescriptor.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				swapChainDescriptor.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				swapChainDescriptor.BufferCount = 1;
				swapChainDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

				swapChainDescriptor.SampleDesc.Count = 1;
				swapChainDescriptor.SampleDesc.Quality = 0;

				swapChainDescriptor.OutputWindow = window_->GetWindowHandle();
				swapChainDescriptor.Windowed = true;

				swapChainDescriptor.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

				swapChainDescriptor.Flags = 0;

				return swapChainDescriptor;
			}

			ComPtr<IDXGIFactory> SwapChain::GetIDXGIFactory() const
			{
				auto device = device_->GetDeviceInterface();

				ComPtr<IDXGIDevice> idxgiDevice;
				HRESULT result = device.As(&idxgiDevice);

				ErrorHandler::HandleWindowsError(result, L"Failed to retrieve IDXGIDevice interface");

				ComPtr<IDXGIAdapter> idxgiAdapter;
				result = idxgiDevice->GetAdapter(&idxgiAdapter);

				ErrorHandler::HandleWindowsError(result, L"Failed to retrieve IDXGIAdapter interface");

				ComPtr<IDXGIFactory> idxgiFactory;
				result = idxgiAdapter->GetParent(IID_IDXGIFactory, &idxgiFactory);

				ErrorHandler::HandleWindowsError(result, L"Failed to retrieve IDXGIFactory interface");

				return idxgiFactory;
			}

			void SwapChain::PresentBackBuffer() const
			{
				swapChain_->Present(0, 0);
			}

			ComPtr<ID3D11Texture2D> SwapChain::GetBackBuffer() const
			{
				ComPtr<ID3D11Texture2D> backBuffer {};

				HRESULT result = swapChain_->GetBuffer(0, IID_ID3D11Texture2D, &backBuffer);

				return backBuffer;
			}
		}
	}
}