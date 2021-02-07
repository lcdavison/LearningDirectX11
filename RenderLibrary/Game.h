#pragma once

#include <memory>

#include "Renderer.h"
#include "GameplayUpdater.h"
#include "ApplicationState.h"

namespace RenderLibrary
{
	namespace Game
	{
		class Game
		{
		protected:
			std::unique_ptr<Rendering::Renderer> renderer_;
			std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater_;

			std::shared_ptr<Window::Window> window_;

			bool isRunning_;

		public:
			Game();
			Game(std::unique_ptr<Rendering::Renderer> renderer, std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater);

			void Run();

		private:
			virtual void Initialise();

			virtual void Start();
			virtual void Stop();

			virtual void Update();
			virtual void Render();
		};
	}
}