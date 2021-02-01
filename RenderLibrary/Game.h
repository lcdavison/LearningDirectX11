#pragma once

#include <memory>

#include "Renderer.h"
#include "GameplayUpdater.h"

namespace RenderLibrary
{
	namespace Game
	{
		class Game
		{
		protected:
			std::unique_ptr<Rendering::Renderer> _renderer;
			std::unique_ptr<Gameplay::GameplayUpdater> _gameplayUpdater;

		public:
			Game();
			Game(std::unique_ptr<Rendering::Renderer> renderer, std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater);

			virtual void Start();
			virtual void Stop();

			virtual void Update();
			virtual void Render();
		};
	}
}