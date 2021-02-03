#pragma once

#include "Module.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		class Renderer : public Module
		{
		public:
			virtual void Render() = 0;

		};
	}
}