#pragma once

#include "Rendering/BaseRenderer.h"
#include "Rendering/GraphicsContext.h"
#include "Exceptions/Exception.h"
#include "ErrorHandler.h"

#include "Rendering/DirectX11/DX11Device.h"
#include "Rendering/DirectX11/DX11SwapChain.h"
#include "Rendering/StaticMesh.h"

#include <wrl.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <memory>

namespace RenderLibrary::Rendering::DirectX11
{
	class DX11Renderer : public BaseRenderer
	{
		std::shared_ptr<GraphicsContext> graphicsContext_;

		/* Testing */
		std::shared_ptr<StaticMesh> drawable_;

	public:
		DX11Renderer();
		virtual ~DX11Renderer() override;

		virtual void Initialise(std::shared_ptr<System::Window> window) override;

		virtual void Start() override;
		virtual void Stop() override;

		virtual void Render() override;
	};

}