#include "Rendering/GraphicsContext.h"

namespace RenderLibrary::Rendering
{
	GraphicsContext::GraphicsContext(std::shared_ptr<Device> device, std::shared_ptr<System::Window> window)
		: device_ {device},
		window_ {window}
	{
		swapChain_ = device_->CreateSwapChain(window_);
		swapChain_->Bind();
	}

	void GraphicsContext::Draw()
	{
		swapChain_->Present();
	}

	void GraphicsContext::Clear()
	{
		swapChain_->Clear();
	}

	std::shared_ptr<Device> GraphicsContext::GetDevice() const
	{
		return device_;
	}
}