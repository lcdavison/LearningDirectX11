#pragma once

#include <wrl.h>
#include <d3d11.h>
#include <memory>

#include "ErrorHandler.h"
#include "Rendering/DirectX11/Device.h"

using namespace Microsoft::WRL;

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			class RenderTargetView
			{
				std::shared_ptr<Device> device_;

				ComPtr<ID3D11RenderTargetView> renderTargetView_;
				ComPtr<ID3D11Texture2D> backBuffer_;

			public:
				RenderTargetView(std::shared_ptr<Device> device, ComPtr<IDXGISwapChain> swapChain);

				void Create();

				ComPtr<ID3D11RenderTargetView> GetView() const;

			private:
				void GetBackBuffer(ComPtr<IDXGISwapChain> swapChain);
			};
		}
	}
}