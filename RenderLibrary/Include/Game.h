#pragma once

#include <memory>

#include "Rendering/BaseRenderer.h"
#include "GameplayUpdater.h"

#include "EventSystem/WindowEvent.h"
#include "EventSystem/EventHandler.h"

#include "Services/EventDispatcher.h"
#include "Services/ServiceRepository.h"

namespace RenderLibrary
{
	namespace Game
	{
		class Game
		{
		protected:
			HINSTANCE instance_;

			std::unique_ptr<Rendering::BaseRenderer> renderer_;
			std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater_;

			std::shared_ptr<Window::Window> window_;

			bool isRunning_;

		public:
			Game(HINSTANCE instance);
			Game(HINSTANCE instance, std::unique_ptr<Rendering::BaseRenderer> renderer, std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater);

			void Run();
			
		private:
			virtual void Initialise();

			virtual void Start();
			virtual void Stop();

			virtual void Update();
			virtual void Render();

			virtual void StartServices();
			virtual void StopServices();

			void SetupEventHandlers();
			virtual void OnWindowEvent(std::shared_ptr<EventSystem::WindowEvent> eventData);
		};
	}
}