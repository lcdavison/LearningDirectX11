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

			virtual void Start() override;
			virtual void Stop() override;

			virtual void Render() override;
		};
	}
}