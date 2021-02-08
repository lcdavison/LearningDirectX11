#pragma once

#include <wrl.h>
#include <d3d11.h>

#include "ErrorHandler.h"

using namespace Microsoft::WRL;

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			class RenderTargetView
			{
				ComPtr<ID3D11RenderTargetView> renderTargetView_;
				ComPtr<ID3D11Texture2D> backBuffer_;

			public:
				RenderTargetView(ComPtr<IDXGISwapChain> swapChain);

				void Create(ComPtr<ID3D11Device> device);

				ComPtr<ID3D11RenderTargetView> GetView() const;

			private:
				void GetBackBuffer(ComPtr<IDXGISwapChain> swapChain);
			};
		}
	}
}