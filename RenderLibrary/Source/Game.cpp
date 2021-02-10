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
			window_ = std::make_shared<Window::Window>(instance_);
			
			renderer_->Initialise(window_);
		}

		void Game::Start()
		{
			StartServices();

			auto eventDispatcher = ServiceRepository::GetService<EventDispatcher>(ServiceID::EventDispatcher);
			eventDispatcher->SubscribeToChannel(EventChannel::Window, std::shared_ptr<Game>(this));

			window_->Start();

			renderer_->Start();
		}

		void Game::StartServices()
		{
			Services::ServiceRepository::StartService<Services::EventDispatcher>();
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

		void Game::Notify(EventSystem::EventChannel channel)
		{
			//isRunning_ = false;
		}
	}
}