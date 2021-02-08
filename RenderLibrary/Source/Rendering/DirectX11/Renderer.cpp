#include "Rendering/DirectX11/Renderer.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			Renderer::Renderer()
			{
			}

			Renderer::~Renderer()
			{
			}

			void Renderer::Initialise(std::shared_ptr<Window::Window> window)
			{
				window_ = window;
			}

			void Renderer::Start()
			{
				CreateDevice();

				CreateSwapChain();

				CreateRenderTargetView();

				CreateDepthStencilView();

				SetRenderTargets();

				SetupViewport();
			}

			void Renderer::CreateDevice()
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

			void Renderer::CreateSwapChain()
			{
				swapChain_.Reset();

				DXGI_SWAP_CHAIN_DESC swapChainDescriptor = CreateSwapChainDescriptor();

				ComPtr<IDXGIFactory> idxgiFactory = GetIDXGIFactory();

				HRESULT result = idxgiFactory->CreateSwapChain(device_.Get(), &swapChainDescriptor, &swapChain_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create swap chain");
			}

			DXGI_SWAP_CHAIN_DESC Renderer::CreateSwapChainDescriptor()
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

			ComPtr<IDXGIFactory> Renderer::GetIDXGIFactory()
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

			void Renderer::CreateRenderTargetView()
			{
				renderTargetView_ = std::make_shared<RenderTargetView>(swapChain_);
				renderTargetView_->Create(device_);
			}

			void Renderer::CreateDepthStencilView()
			{
				depthStencilView_ = std::make_shared<DepthStencilView>(device_);
				depthStencilView_->Create();
			}

			void Renderer::SetRenderTargets()
			{
				ID3D11RenderTargetView** renderTargetView = &renderTargetView_->GetView();
				ID3D11DepthStencilView* depthStencilView = depthStencilView_->GetView().Get();

				deviceContext_->OMSetRenderTargets(1, renderTargetView, depthStencilView);
			}

			void Renderer::SetupViewport()
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

			void Renderer::Stop()
			{
			}

			void Renderer::Render()
			{
				ClearRenderTargets();



				swapChain_->Present(0, 0);
			}

			void Renderer::ClearRenderTargets()
			{
				XMFLOAT4 clearColour {0.0f, 1.0f, 0.0f, 1.0f};
				deviceContext_->ClearRenderTargetView(renderTargetView_->GetView().Get(), reinterpret_cast<float*>(&clearColour));

				deviceContext_->ClearDepthStencilView(depthStencilView_->GetView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
			}
		}
	}
}