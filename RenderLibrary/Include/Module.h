#pragma once

namespace RenderLibrary
{
	class Module
	{
	public:
		virtual ~Module() = default;

		virtual void Start() = 0;
		virtual void Stop() = 0;

	};
}