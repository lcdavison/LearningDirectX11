#include "Rendering/DirectX11/DX11Renderer.h"

namespace RenderLibrary::Rendering::DirectX11
{
	DX11Renderer::DX11Renderer()
	{
	}

	DX11Renderer::~DX11Renderer()
	{
	}

	void DX11Renderer::Initialise(std::shared_ptr<Window> window)
	{
		window_ = window;
	}

	void DX11Renderer::Start()
	{
		graphicsContext_ = std::make_shared<GraphicsContext>(std::make_shared<DX11Device>(), window_);
	}

	void DX11Renderer::Stop()
	{
	}

	void DX11Renderer::Render()
	{
		graphicsContext_->Clear();



		graphicsContext_->Draw();
	}
}