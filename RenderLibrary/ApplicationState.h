#pragma once

#include <Windows.h>

namespace RenderLibrary
{
	struct ApplicationState
	{
		static HINSTANCE instance;
		static INT showCommand;
	};
}