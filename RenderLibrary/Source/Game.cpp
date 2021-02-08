#include "Game.h"

#include "Rendering/DefaultRenderer.h"
#include "DefaultGameplayUpdater.h"
#include "Rendering/DirectX11/Renderer.h"

namespace RenderLibrary
{
	namespace Game
	{
		Game::Game()
			: Game(std::make_unique<Rendering::DirectX11::Renderer>(),
				   std::make_unique<Gameplay::DefaultGameplayUpdater>())
		{
		}

		Game::Game(std::unique_ptr<Rendering::BaseRenderer> renderer,
				   std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater)
			: renderer_(std::move(renderer)),
			gameplayUpdater_(std::move(gameplayUpdater)),
			isRunning_(false)
		{
		}

		void Game::Run()
		{
			Initialise();

			Start();

			while (true)
			{
				Update();
				Render();
			}

			Stop();
		}

		void Game::Initialise()
		{
			window_ = std::make_shared<Window::Window>(ApplicationState::instance);
			window_->MakeVisible();

			renderer_->Initialise(window_);
		}

		void Game::Start()
		{
			renderer_->Start();
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
		}
	}
}