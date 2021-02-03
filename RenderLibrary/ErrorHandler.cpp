#include "ErrorHandler.h"

namespace RenderLibrary
{
	void ErrorHandler::HandleWindowsError(HRESULT result, const std::wstring& errorMessage)
	{
		if (FAILED(result))
		{
			throw Exception(errorMessage.c_str());
		}
	}
}