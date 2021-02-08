#include "Rendering/DirectX11/Device.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		namespace DirectX11
		{
			Device::Device()
			{
			}

			void Device::Create()
			{
				UINT flags {};

				D3D_FEATURE_LEVEL featureLevel {};

				HRESULT result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, nullptr, 0, D3D11_SDK_VERSION, &device_, &featureLevel, &deviceContext_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create DirectX 11 device");

				if (featureLevel != D3D_FEATURE_LEVEL_11_0)
				{
					throw Exception(L"DirectX 11 not supported");
				}
			}

			ComPtr<ID3D11Device> Device::GetDeviceInterface() const
			{
				return device_;
			}

			ComPtr<ID3D11DeviceContext> Device::GetContextInterface() const
			{
				return deviceContext_;
			}
		}
	}
}