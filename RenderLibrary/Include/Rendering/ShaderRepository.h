#pragma once

#include <unordered_map>
#include <memory>

#include <d3d11.h>
#include <wrl.h>

#include "ShaderType.h"
#include "Exceptions/Exception.h"
#include "ErrorHandler.h"
#include "Device.h"

namespace RenderLibrary::Rendering
{
	class ShaderRepository
	{
		std::shared_ptr<Device> device_;

	public:
		ShaderRepository(std::shared_ptr<Device> device);

		void LoadShaderFromBinaryFile(const std::wstring& filePath, ShaderType shaderType);

	private:
		std::string GetEntryPointName(ShaderType shaderType) const;
		std::string GetProfileName(ShaderType shaderType) const;

	};
}