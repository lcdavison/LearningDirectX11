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

				HRESULT result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, nullptr, 0, D3D11_SDK_VERSION, &deviceInterface_, &featureLevel, &contextInterface_);

				ErrorHandler::HandleWindowsError(result, L"Failed to create DirectX 11 device");

				if (featureLevel != D3D_FEATURE_LEVEL_11_0)
				{
					throw Exception(L"DirectX 11 not supported");
				}
			}

			DXGI_SAMPLE_DESC Device::GetMultiSamplingDescriptor(int sampleCount) const
			{
				DXGI_SAMPLE_DESC sampleDescriptor {};

				UINT multiSamplingQuality {};
				deviceInterface_->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, sampleCount, &multiSamplingQuality);

				/*
				*	Multi sampling quality is greater than zero, when multi sampling
				*	is supported for a provided number of samples.
				*/
				if (multiSamplingQuality > 0)
				{
					sampleDescriptor.Count = sampleCount;
					sampleDescriptor.Quality = multiSamplingQuality - 1;
				}
				else
				{
					sampleDescriptor.Count = 1;
					sampleDescriptor.Quality = 0;
				}

				return sampleDescriptor;
			}

			ComPtr<ID3D11Device> Device::GetDeviceInterface() const
			{
				return deviceInterface_;
			}

			ComPtr<ID3D11DeviceContext> Device::GetContextInterface() const
			{
				return contextInterface_;
			}
		}
	}
}