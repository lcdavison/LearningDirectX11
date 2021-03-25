#include "Rendering/ShaderRepository.h"

using namespace Microsoft::WRL;

namespace RenderLibrary::Rendering
{
	ShaderRepository::ShaderRepository(std::shared_ptr<Device> device)
		: device_(device)
	{
	}

	void ShaderRepository::LoadShaderFromBinaryFile(const std::wstring& filePath, ShaderType shaderType)
	{
		ComPtr<ID3DBlob> shaderCodeBlob;
		ComPtr<ID3DBlob> errorMessageBlob;

		auto entryPointName = GetEntryPointName(shaderType);
		auto profileName = GetProfileName(shaderType);
		

	}

	std::string ShaderRepository::GetEntryPointName(ShaderType shaderType) const
	{
		switch (shaderType)
		{
		case ShaderType::VERTEX:
			{
				return "VSMain";
			}
		case ShaderType::PIXEL:
			{
				return "PSMain";
			}
		default:
			{
				throw Exception(L"Unknown shader type");
			}
		}
	}

	std::string ShaderRepository::GetProfileName(ShaderType shaderType) const
	{
		switch (shaderType)
		{
		case ShaderType::VERTEX:
			{
				return "vs_5_0";
			}
		case ShaderType::PIXEL:
			{
				return "ps_5_0";
			}
		default:
			{
				throw Exception(L"Unknown shader type");
			}
		}
	}
}