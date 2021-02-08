#pragma once

#include "Rendering/BaseRenderer.h"
#include "Exceptions/Exception.h"
#include "ErrorHandler.h"
#include "Rendering/DirectX11/RenderTargetView.h"
#include "Rendering/DirectX11/DepthStencilView.h"
#include "Rendering/DirectX11/Device.h"
#include "Rendering/DirectX11/SwapChain.h"

#include <wrl.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <memory>

using namespace Microsoft::WRL;
using namespace DirectX;

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			class Renderer : public BaseRenderer
			{
				std::shared_ptr<Device> device_;
				std::shared_ptr<SwapChain> swapChain_;
				std::shared_ptr<RenderTargetView> renderTargetView_;
				std::shared_ptr<DepthStencilView> depthStencilView_;

			public:
				Renderer();
				virtual ~Renderer() override;

				virtual void Initialise(std::shared_ptr<Window::Window> window) override;

				virtual void Start() override;
				virtual void Stop() override;

				virtual void Render() override;

			private:
				void SetRenderTargets();
				
				void ClearRenderTargets();

				void SetupViewport();
			};
		}
	}
}