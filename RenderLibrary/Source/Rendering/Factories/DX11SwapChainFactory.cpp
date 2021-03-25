#include "Rendering/Factories/DX11SwapChainFactory.h"

using namespace Microsoft::WRL;
using namespace RenderLibrary::System;

namespace RenderLibrary::Rendering::Factory
{
	DX11SwapChainFactory::DX11SwapChainFactory(ComPtr<ID3D11Device> deviceInterface,
											   ComPtr<ID3D11DeviceContext> contextInterface)
		: deviceInterface_ {deviceInterface},
		contextInterface_ {contextInterface}
	{
	}

	std::shared_ptr<SwapChain> DX11SwapChainFactory::CreateSwapChain(std::shared_ptr<Window> window)
	{
		auto swapChainInterface = CreateDXGISwapChain(window);

		ComPtr<ID3D11Texture2D> backBuffer {};
		auto result = swapChainInterface->GetBuffer(0, IID_ID3D11Texture2D, &backBuffer);

		ErrorHandler::HandleWindowsError(result, L"Failed to get back buffer");

		auto renderTargetView = CreateRenderTargetView(backBuffer);

		auto depthStencilBuffer = CreateDepthStencilBuffer();

		auto depthStencilView = CreateDepthStencilView(depthStencilBuffer);

		return std::make_shared<DirectX11::DX11SwapChain>(contextInterface_, swapChainInterface, renderTargetView, depthStencilView, depthStencilBuffer);
	}

	ComPtr<IDXGISwapChain> DX11SwapChainFactory::CreateDXGISwapChain(std::shared_ptr<Window> window)
	{
		ComPtr<IDXGISwapChain> swapChainInterface {};

		auto swapChainDescriptor = CreateSwapChainDescriptor(window);

		auto idxgiFactory = GetIDXGIFactory();
		auto result = idxgiFactory->CreateSwapChain(deviceInterface_.Get(), &swapChainDescriptor, &swapChainInterface);

		ErrorHandler::HandleWindowsError(result, L"Failed to create Swap Chain");

		return swapChainInterface;
	}

	DXGI_SWAP_CHAIN_DESC DX11SwapChainFactory::CreateSwapChainDescriptor(std::shared_ptr<Window> window)
	{
		DXGI_SWAP_CHAIN_DESC swapChainDescriptor {};

		swapChainDescriptor.BufferDesc.Width = 1280;
		swapChainDescriptor.BufferDesc.Height = 720;
		swapChainDescriptor.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDescriptor.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDescriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDescriptor.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapChainDescriptor.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		swapChainDescriptor.BufferCount = 1;
		swapChainDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

		swapChainDescriptor.SampleDesc = GetMultiSamplingDescriptor(4);

		swapChainDescriptor.OutputWindow = window->GetWindowHandle();
		swapChainDescriptor.Windowed = true;

		swapChainDescriptor.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		swapChainDescriptor.Flags = 0;

		return swapChainDescriptor;
	}

	DXGI_SAMPLE_DESC DX11SwapChainFactory::GetMultiSamplingDescriptor(int sampleCount) const
	{
		DXGI_SAMPLE_DESC sampleDescriptor {};

		UINT multiSamplingQuality {};
		auto result = deviceInterface_->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, sampleCount, &multiSamplingQuality);

		ErrorHandler::HandleWindowsError(result, L"Failed to get multi sample quality");

		/*
		*	Multi sampling quality is greater than zero, when multi sampling
		*	is supported for a provided number of samples.
		*/
		if (multiSamplingQuality > 0)
		{
			sampleDescriptor.Count = sampleCount;
			sampleDescriptor.Quality = multiSamplingQuality - 1;
		}
		else
		{
			sampleDescriptor.Count = 1;
			sampleDescriptor.Quality = 0;
		}

		return sampleDescriptor;
	}

	ComPtr<IDXGIFactory> DX11SwapChainFactory::GetIDXGIFactory() const
	{
		ComPtr<IDXGIDevice> idxgiDevice {};
		auto result = deviceInterface_.As(&idxgiDevice);

		ErrorHandler::HandleWindowsError(result, L"Failed to get IDXGI Device");

		ComPtr<IDXGIAdapter> idxgiAdapter {};
		result = idxgiDevice->GetAdapter(&idxgiAdapter);

		ErrorHandler::HandleWindowsError(result, L"Failed to get IDXGI Adapter");

		ComPtr<IDXGIFactory> idxgiFactory {};
		result = idxgiAdapter->GetParent(IID_IDXGIFactory, &idxgiFactory);

		ErrorHandler::HandleWindowsError(result, L"Failed to get IDXGI Factory");

		return idxgiFactory;
	}

	ComPtr<ID3D11RenderTargetView> DX11SwapChainFactory::CreateRenderTargetView(ComPtr<ID3D11Texture2D> backBuffer)
	{
		ComPtr<ID3D11RenderTargetView> renderTargetView {};

		auto result = deviceInterface_->CreateRenderTargetView(backBuffer.Get(), nullptr, &renderTargetView);

		ErrorHandler::HandleWindowsError(result, L"Failed to create Render View Target");

		return renderTargetView;
	}

	ComPtr<ID3D11Texture2D> DX11SwapChainFactory::CreateDepthStencilBuffer()
	{
		ComPtr<ID3D11Texture2D> depthStencilBuffer {};

		auto depthStencilViewDescriptor = CreateDepthStencilBufferDescriptor();
		auto result = deviceInterface_->CreateTexture2D(&depthStencilViewDescriptor, nullptr, &depthStencilBuffer);

		ErrorHandler::HandleWindowsError(result, L"Failed to create Depth Stencil Buffer");

		return depthStencilBuffer;
	}

	D3D11_TEXTURE2D_DESC DX11SwapChainFactory::CreateDepthStencilBufferDescriptor()
	{
		D3D11_TEXTURE2D_DESC depthStencilViewDescriptor {};

		depthStencilViewDescriptor.Width = 1280;
		depthStencilViewDescriptor.Height = 720;

		depthStencilViewDescriptor.MipLevels = 1;

		depthStencilViewDescriptor.ArraySize = 1;

		depthStencilViewDescriptor.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

		depthStencilViewDescriptor.SampleDesc.Count = 1;
		depthStencilViewDescriptor.SampleDesc.Quality = 0;

		depthStencilViewDescriptor.Usage = D3D11_USAGE_DEFAULT;

		depthStencilViewDescriptor.BindFlags = D3D11_BIND_DEPTH_STENCIL;

		depthStencilViewDescriptor.CPUAccessFlags = 0;
		depthStencilViewDescriptor.MiscFlags = 0;

		return depthStencilViewDescriptor;
	}

	ComPtr<ID3D11DepthStencilView> DX11SwapChainFactory::CreateDepthStencilView(ComPtr<ID3D11Texture2D> depthStencilBuffer)
	{
		ComPtr<ID3D11DepthStencilView> depthStencilView {};
		
		auto result = deviceInterface_->CreateDepthStencilView(depthStencilBuffer.Get(), nullptr, &depthStencilView);

		ErrorHandler::HandleWindowsError(result, L"Failed to create Depth Stencil View");

		return depthStencilView;
	}
}