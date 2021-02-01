#include "Game.h"

#include "DefaultRenderer.h"
#include "DefaultGameplayUpdater.h"

namespace RenderLibrary
{
	namespace Game
	{
		Game::Game()
			: Game(std::make_unique<Rendering::DefaultRenderer>(), 
				   std::make_unique<Gameplay::DefaultGameplayUpdater>())
		{
		}

		Game::Game(std::unique_ptr<Rendering::Renderer> renderer, 
				   std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater)
			: _renderer(std::move(renderer)),
			_gameplayUpdater(std::move(gameplayUpdater))
		{
		}

		void Game::Start()
		{			
		}

		void Game::Stop()
		{
		}

		void Game::Update()
		{
			_gameplayUpdater->Update();
		}

		void Game::Render()
		{
			_renderer->Render();
		}
	}
}