#pragma once

#include <Windows.h>
#include <string>

#include "Exceptions/Exception.h"

namespace RenderLibrary
{
	class ErrorHandler
	{
	public:
		static void HandleWindowsError(HRESULT result, const std::wstring& errorMessage);
	};
}