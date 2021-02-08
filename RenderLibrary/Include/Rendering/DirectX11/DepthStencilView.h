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
			class DepthStencilView
			{
				ComPtr<ID3D11Device> device_;
				ComPtr<ID3D11DepthStencilView> depthStencilView_;
				ComPtr<ID3D11Texture2D> buffer_;

			public:
				DepthStencilView(ComPtr<ID3D11Device> device);

				void Create();

				ComPtr<ID3D11DepthStencilView> GetView() const;

			private:
				void CreateBuffer();

				void CreateDepthStencilView();
			};
		}
	}
}