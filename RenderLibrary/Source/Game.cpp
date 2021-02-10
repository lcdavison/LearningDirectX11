#include "Game.h"

#include "Rendering/DefaultRenderer.h"
#include "DefaultGameplayUpdater.h"
#include "Rendering/DirectX11/Renderer.h"

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
			window_->MakeVisible();

			renderer_->Initialise(window_);
		}

		void Game::Start()
		{
			StartServices();

			renderer_->Start();
		}

		void Game::StartServices()
		{
			Services::ServiceRepository::StartService<EventSystem::EventDispatcher>();
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
			switch (channel)
			{
			case EventSystem::EventChannel::General:
				throw Exception(L"General channel has received a message");
				break;
			case EventSystem::EventChannel::Window:
				throw Exception(L"Window channel has received a message");
				break;
			default:
				throw Exception(L"Unsupported event channel");
				break;
			}
		}
	}
}