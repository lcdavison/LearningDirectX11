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
				swapChain_ = std::make_shared<SwapChain>(device_, window);
				renderTargetView_ = std::make_shared<RenderTargetView>(device_, swapChain_);
				depthStencilView_ = std::make_shared<DepthStencilView>(device_);
			}

			void Renderer::Start()
			{
				device_->Create();

				swapChain_->Create();

				renderTargetView_->Create();

				depthStencilView_->Create();

				SetRenderTargets();

				SetupViewport();
			}

			void Renderer::SetRenderTargets()
			{
				auto deviceContext = device_->GetContextInterface();

				auto renderTargetViews = &(renderTargetView_->GetView());
				auto depthStencilView = depthStencilView_->GetView();

				deviceContext->OMSetRenderTargets(1, renderTargetViews, depthStencilView.Get());
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


				swapChain_->PresentBackBuffer();
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