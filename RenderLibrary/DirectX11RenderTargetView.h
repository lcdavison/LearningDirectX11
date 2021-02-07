#pragma once

#include <wrl.h>
#include <d3d11.h>

#include "ErrorHandler.h"

using namespace Microsoft::WRL;

namespace RenderLibrary
{
	namespace Rendering
	{
		class DirectX11RenderTargetView
		{
			ComPtr<ID3D11RenderTargetView> renderTargetView_;
			ComPtr<ID3D11Texture2D> backBuffer_;

		public:
			DirectX11RenderTargetView(ComPtr<IDXGISwapChain> swapChain);

			void Create(ComPtr<ID3D11Device> device);

			ComPtr<ID3D11RenderTargetView> GetView() const;

		private:
			void GetBackBuffer(ComPtr<IDXGISwapChain> swapChain);
		};
	}
}