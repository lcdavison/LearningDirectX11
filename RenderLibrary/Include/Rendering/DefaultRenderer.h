#pragma once

#include "BaseRenderer.h"

namespace RenderLibrary
{
	namespace Rendering
	{
		class DefaultRenderer : public BaseRenderer
		{
		public:
			DefaultRenderer();

			virtual void Start() override;
			virtual void Stop() override;

			virtual void Render() override;
		};
	}
}