#include "Game.h"

#include "Rendering/DefaultRenderer.h"
#include "DefaultGameplayUpdater.h"
#include "Rendering/DirectX11/DX11Renderer.h"

using namespace RenderLibrary::Services;
using namespace RenderLibrary::EventSystem;

namespace RenderLibrary::Game
{
	Win32Game::Win32Game(HINSTANCE instance)
		: Win32Game(instance,
					std::make_unique<Rendering::DirectX11::DX11Renderer>(),
					std::make_unique<Gameplay::DefaultGameplayUpdater>())
	{
	}

	Win32Game::Win32Game(HINSTANCE instance,
						 std::unique_ptr<Rendering::BaseRenderer> renderer,
						 std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater)
		: instance_(instance),
		renderer_(std::move(renderer)),
		gameplayUpdater_(std::move(gameplayUpdater)),
		isRunning_(false)
	{
	}

	int Win32Game::Run()
	{
		isRunning_ = true;

		Initialise();

		Start();

		while (isRunning_)
		{
			Update();
			Render();
		}

		Stop();

		return 0;
	}

	void Win32Game::Initialise()
	{
		SetupEventPrototypes();

		window_ = std::make_shared<Window>(instance_);

		renderer_->Initialise(window_);
	}

	void Win32Game::SetupEventPrototypes()
	{
		using namespace EventSystem;

		EventRegistry::CreateAndRegisterEvent<WindowEvent>();
	}

	void Win32Game::Start()
	{
		StartServices();

		SetupEventHandlers();

		window_->Start();

		renderer_->Start();
	}

	void Win32Game::StartServices()
	{
		Services::ServiceRepository::StartService<Services::EventDispatcher>();
	}

	void Win32Game::SetupEventHandlers()
	{
		auto eventDispatcher = ServiceRepository::GetService<EventDispatcher>(ServiceID::EventDispatcher);

		auto windowEventHandler = std::make_shared<EventHandler<WindowEvent>>(std::bind(&Win32Game::OnWindowEvent, this, std::placeholders::_1));
		eventDispatcher->SubscribeToEvent<WindowEvent>(windowEventHandler);
	}

	void Win32Game::Update()
	{
		window_->Update();

		gameplayUpdater_->Update();
	}

	void Win32Game::Render()
	{
		renderer_->Render();
	}

	void Win32Game::Stop()
	{
		StopServices();
	}

	void Win32Game::StopServices()
	{
	}

	void Win32Game::OnWindowEvent(std::shared_ptr<WindowEvent> eventData)
	{
		if (eventData->HasWindowClosed)
		{
			isRunning_ = false;
		}
	}
}