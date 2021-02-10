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
			class Device
			{
				ComPtr<ID3D11Device> deviceInterface_;
				ComPtr<ID3D11DeviceContext> contextInterface_;

			public:
				Device();

				void Create();

				DXGI_SAMPLE_DESC GetMultiSamplingDescriptor(int sampleCount) const;

				ComPtr<ID3D11Device> GetDeviceInterface() const;
				ComPtr<ID3D11DeviceContext> GetContextInterface() const;
			};
		}
	}
}