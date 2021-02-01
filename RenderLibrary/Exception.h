#pragma once

#include <exception>
#include <string>

namespace RenderLibrary
{
	class Exception : public std::exception
	{
		std::wstring _errorMessage;

	public:
		Exception();
		Exception(const std::wstring& error);

		const std::wstring& GetErrorMessage() const;
	};
}