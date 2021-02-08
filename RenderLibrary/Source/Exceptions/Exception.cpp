#include "Exception.h"

namespace RenderLibrary
{
	Exception::Exception() : _errorMessage(L"Unknown error")
	{
	}

	Exception::Exception(const std::wstring& error) : _errorMessage(error)
	{
	}

	const std::wstring& Exception::GetErrorMessage() const
	{
		return _errorMessage;
	}
}