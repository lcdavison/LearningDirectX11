#include "DirectX11Renderer.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		DirectX11Renderer::DirectX11Renderer()
		{
		}

		void DirectX11Renderer::Start()
		{
			CreateDevice();
			CreateSwapChain();
		}

		void DirectX11Renderer::Stop()
		{
		}

		void DirectX11Renderer::Render()
		{
		}

		void DirectX11Renderer::CreateDevice()
		{
			UINT flags = 0;

			D3D_FEATURE_LEVEL featureLevel;

			HRESULT result = D3D11CreateDevice(
				NULL, D3D_DRIVER_TYPE_HARDWARE, 
				NULL, flags, NULL, 0, 
				D3D11_SDK_VERSION, &_device, &featureLevel, &_deviceContext);

			ErrorHandler::HandleWindowsError(result, L"Failed to create D3D11 Device");

			if (featureLevel != D3D_FEATURE_LEVEL_11_0)
			{
				throw Exception(L"DirectX 11 not supported");
			}
		}

		void DirectX11Renderer::CreateSwapChain()
		{
			DXGI_SWAP_CHAIN_DESC swapChainDescriptor = CreateSwapChainDescriptor();

			
		}

		DXGI_SWAP_CHAIN_DESC DirectX11Renderer::CreateSwapChainDescriptor()
		{
			DXGI_SWAP_CHAIN_DESC swapChainDescriptor {};

			swapChainDescriptor.BufferDesc.Width = 1280;
			swapChainDescriptor.BufferDesc.Height = 1280;
			swapChainDescriptor.BufferDesc.RefreshRate.Numerator = 60;
			swapChainDescriptor.BufferDesc.RefreshRate.Denominator = 1;
			swapChainDescriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			swapChainDescriptor.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
			swapChainDescriptor.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

			swapChainDescriptor.BufferCount = 1;
			swapChainDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

			swapChainDescriptor.SampleDesc.Count = 1;
			swapChainDescriptor.SampleDesc.Quality = 0;

			swapChainDescriptor.OutputWindow = NULL;
			swapChainDescriptor.Windowed = true;

			swapChainDescriptor.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

			swapChainDescriptor.Flags = 0;
		}
	}
}