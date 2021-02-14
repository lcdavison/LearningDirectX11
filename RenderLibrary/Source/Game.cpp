#include "Game.h"

#include "Rendering/DefaultRenderer.h"
#include "DefaultGameplayUpdater.h"
#include "Rendering/DirectX11/Renderer.h"

using namespace RenderLibrary::Services;
using namespace RenderLibrary::EventSystem;

namespace RenderLibrary
{
	namespace Game
	{
		Game::Game(HINSTANCE instance)
			: Game(instance,
				   std::make_unique<Rendering::DirectX11::Renderer>(),
				   std::make_unique<Gameplay::DefaultGameplayUpdater>())
		{
		}

		Game::Game(HINSTANCE instance,
				   std::unique_ptr<Rendering::BaseRenderer> renderer,
				   std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater)
			: instance_(instance),
			renderer_(std::move(renderer)),
			gameplayUpdater_(std::move(gameplayUpdater)),
			isRunning_(false)
		{
		}

		void Game::Run()
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
		}

		void Game::Initialise()
		{
			SetupEventPrototypes();

			window_ = std::make_shared<Window::Window>(instance_);
			
			renderer_->Initialise(window_);
		}

		void Game::SetupEventPrototypes()
		{
			using namespace EventSystem;

			EventRegistry::CreateAndRegisterEvent<WindowEvent>();
		}

		void Game::Start()
		{
			StartServices();

			SetupEventHandlers();

			window_->Start();

			renderer_->Start();
		}

		void Game::StartServices()
		{
			Services::ServiceRepository::StartService<Services::EventDispatcher>();
		}

		void Game::SetupEventHandlers()
		{
			auto eventDispatcher = ServiceRepository::GetService<EventDispatcher>(ServiceID::EventDispatcher);

			auto windowEventHandler = std::make_shared<EventHandler<WindowEvent>>(std::bind(&Game::OnWindowEvent, this, std::placeholders::_1));
			eventDispatcher->SubscribeToEvent<WindowEvent>(windowEventHandler);
		}

		void Game::Update()
		{
			window_->Update();

			gameplayUpdater_->Update();
		}

		void Game::Render()
		{
			renderer_->Render();
		}

		void Game::Stop()
		{
			StopServices();
		}

		void Game::StopServices()
		{
		}

		void Game::OnWindowEvent(std::shared_ptr<WindowEvent> eventData)
		{
			if (eventData->HasWindowClosed)
			{
				isRunning_ = false;
			}
		}
	}
}