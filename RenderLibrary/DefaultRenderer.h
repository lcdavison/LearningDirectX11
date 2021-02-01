#pragma once

#include "Renderer.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		class DefaultRenderer : public Renderer
		{
		public:
			DefaultRenderer();

			virtual void Render() override;
		};
	}
}