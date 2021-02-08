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

				device_ = std::make_shared<Device>();
				device_->Create();
			}

			void Renderer::Start()
			{
				CreateSwapChain();

				CreateRenderTargetView();

				CreateDepthStencilView();

				SetRenderTargets();

				SetupViewport();
			}

			void Renderer::CreateSwapChain()
			{
				swapChain_.Reset();

				DXGI_SWAP_CHAIN_DESC swapChainDescriptor = CreateSwapChainDescriptor();

				ComPtr<IDXGIFactory> idxgiFactory = GetIDXGIFactory();

				auto device = device_->GetDeviceInterface();
				HRESULT result = idxgiFactory->CreateSwapChain(device.Get(), &swapChainDescriptor, &swapChain_);

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

			void Renderer::CreateRenderTargetView()
			{
				renderTargetView_ = std::make_shared<RenderTargetView>(device_, swapChain_);
				renderTargetView_->Create();
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

				auto deviceContext = device_->GetContextInterface();
				deviceContext->OMSetRenderTargets(1, renderTargetView, depthStencilView);
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

				auto deviceContext = device_->GetContextInterface();
				deviceContext->RSSetViewports(1, &viewport);
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
				auto deviceContext = device_->GetContextInterface();

				XMFLOAT4 clearColour {0.0f, 1.0f, 0.0f, 1.0f};
				deviceContext->ClearRenderTargetView(renderTargetView_->GetView().Get(), reinterpret_cast<float*>(&clearColour));

				deviceContext->ClearDepthStencilView(depthStencilView_->GetView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
			}
		}
	}
}