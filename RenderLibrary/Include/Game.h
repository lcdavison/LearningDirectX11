#pragma once

#include <memory>

#include "Application.h"

#include "Rendering/BaseRenderer.h"
#include "Gameplay/GameplayUpdater.h"

#include "EventSystem/EventRegistry.h"
#include "EventSystem/Events/WindowEvent.h"
#include "EventSystem/EventHandler.h"

#include "Services/EventDispatcher.h"
#include "Services/ServiceRepository.h"

namespace RenderLibrary::Game
{
	class Win32Game : public Application
	{
	protected:
		HINSTANCE instance_;

		std::unique_ptr<Rendering::BaseRenderer> renderer_;
		std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater_;

		std::shared_ptr<Window> window_;

		bool isRunning_;

	public:
		Win32Game(HINSTANCE instance);
		Win32Game(HINSTANCE instance, std::unique_ptr<Rendering::BaseRenderer> renderer, std::unique_ptr<Gameplay::GameplayUpdater> gameplayUpdater);

		virtual int Run() override;

	private:
		virtual void Initialise();

		virtual void Start();
		virtual void Stop();

		virtual void Update();
		virtual void Render();

		virtual void StartServices();
		virtual void StopServices();

		void SetupEventPrototypes();
		void SetupEventHandlers();

		virtual void OnWindowEvent(std::shared_ptr<EventSystem::WindowEvent> eventData);
	};
}