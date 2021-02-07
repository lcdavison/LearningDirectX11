#include "DirectX11Renderer.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		DirectX11Renderer::DirectX11Renderer()
		{
		}

		DirectX11Renderer::~DirectX11Renderer()
		{
		}

		void DirectX11Renderer::Initialise(std::shared_ptr<Window::Window> window)
		{
			window_ = window;
		}

		void DirectX11Renderer::Start()
		{
			CreateDevice();

			CreateSwapChain();

			CreateRenderTargetView();

			CreateDepthStencilView();

			SetRenderTargets();

			SetupViewport();
		}

		void DirectX11Renderer::CreateDevice()
		{
			UINT flags = 0;

			D3D_FEATURE_LEVEL featureLevel;

			HRESULT result = D3D11CreateDevice(
				NULL, D3D_DRIVER_TYPE_HARDWARE,
				NULL, flags, NULL, 0,
				D3D11_SDK_VERSION, &device_, &featureLevel, &deviceContext_);

			ErrorHandler::HandleWindowsError(result, L"Failed to create D3D11 Device");

			if (featureLevel != D3D_FEATURE_LEVEL_11_0)
			{
				throw Exception(L"DirectX 11 not supported");
			}
		}

		void DirectX11Renderer::CreateSwapChain()
		{
			swapChain_.Reset();

			DXGI_SWAP_CHAIN_DESC swapChainDescriptor = CreateSwapChainDescriptor();

			ComPtr<IDXGIFactory> idxgiFactory = GetIDXGIFactory();

			HRESULT result = idxgiFactory->CreateSwapChain(device_.Get(), &swapChainDescriptor, &swapChain_);

			ErrorHandler::HandleWindowsError(result, L"Failed to create swap chain");
		}

		DXGI_SWAP_CHAIN_DESC DirectX11Renderer::CreateSwapChainDescriptor()
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

		ComPtr<IDXGIFactory> DirectX11Renderer::GetIDXGIFactory()
		{
			ComPtr<IDXGIDevice> idxgiDevice;
			HRESULT result = device_.As(&idxgiDevice);

			ErrorHandler::HandleWindowsError(result, L"Failed to retrieve IDXGIDevice interface");

			ComPtr<IDXGIAdapter> idxgiAdapter;
			result = idxgiDevice->GetAdapter(&idxgiAdapter);

			ErrorHandler::HandleWindowsError(result, L"Failed to retrieve IDXGIAdapter interface");

			ComPtr<IDXGIFactory> idxgiFactory;
			result = idxgiAdapter->GetParent(IID_IDXGIFactory, &idxgiFactory);

			ErrorHandler::HandleWindowsError(result, L"Failed to retrieve IDXGIFactory interface");

			return idxgiFactory;
		}

		void DirectX11Renderer::CreateRenderTargetView()
		{
			renderTargetView_ = std::make_shared<DirectX11RenderTargetView>(swapChain_);
			renderTargetView_->Create(device_);
		}

		void DirectX11Renderer::CreateDepthStencilView()
		{
			depthStencilView_ = std::make_shared<DirectX11DepthStencilView>(device_);
			depthStencilView_->Create();
		}

		void DirectX11Renderer::SetRenderTargets()
		{
			ID3D11RenderTargetView** renderTargetView = &renderTargetView_->GetView();
			ID3D11DepthStencilView* depthStencilView = depthStencilView_->GetView().Get();

			deviceContext_->OMSetRenderTargets(1, renderTargetView, depthStencilView);
		}

		void DirectX11Renderer::SetupViewport()
		{
			D3D11_VIEWPORT viewport {};
			
			viewport.Width = 1280;
			viewport.Height = 720;
			
			viewport.MaxDepth = 1.0f;
			viewport.MinDepth = 0.0f;

			viewport.TopLeftX = 0.0f;
			viewport.TopLeftY = 0.0f;

			deviceContext_->RSSetViewports(1, &viewport);
		}

		void DirectX11Renderer::Stop()
		{
		}

		void DirectX11Renderer::Render()
		{

		}
	}
}