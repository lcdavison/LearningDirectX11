#pragma once

#include "EventSystem/EventListener.h"
#include "EventSystem/EventHandler.h"
#include "EventSystem/EventChannel.h"
#include "EventSystem/Events/Event.h"

#include "Services/Service.h"

#include <unordered_map>
#include <vector>
#include <memory>

namespace RenderLibrary
{
	namespace Services
	{
		class EventDispatcher : public Services::Service
		{
			std::unordered_map<EventSystem::EventChannel, std::vector<std::shared_ptr<EventSystem::BaseEventHandler>>> eventChannels_;

		public:
			EventDispatcher();

			virtual void Start() override;
			virtual void Stop() override;

			void SubscribeToChannel(EventSystem::EventChannel channel, std::shared_ptr<EventSystem::BaseEventHandler> eventHandler);

			void PublishToChannel(EventSystem::EventChannel channel, std::shared_ptr<EventSystem::Event> eventData);

		};
	}
}