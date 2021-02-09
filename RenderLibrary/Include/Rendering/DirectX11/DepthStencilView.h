#pragma once

#include <wrl.h>
#include <d3d11.h>
#include <memory>

#include "Rendering/DirectX11/Device.h"
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
				std::shared_ptr<Device> device_;

				ComPtr<ID3D11DepthStencilView> depthStencilViewInterface_;
				ComPtr<ID3D11Texture2D> bufferInterface_;

			public:
				DepthStencilView(std::shared_ptr<Device> device);

				void Create();

				ComPtr<ID3D11DepthStencilView> GetViewInterface() const;

			private:
				void CreateBuffer();

				void CreateDepthStencilView();
			};
		}
	}
}