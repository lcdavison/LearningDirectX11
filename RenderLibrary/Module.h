#pragma once

namespace RenderLibrary
{
	class Module
	{
	public:
		virtual void Start() = 0;
		virtual void Stop() = 0;

	};
}