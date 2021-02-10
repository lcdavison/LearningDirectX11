#pragma once

#include "EventSystem/EventListener.h"
#include "EventSystem/EventChannel.h"
#include "EventSystem/EventData.h"
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
			std::unordered_map<EventSystem::EventChannel, std::vector<std::shared_ptr<EventSystem::EventListener>>> eventChannels_;

		public:
			EventDispatcher();

			virtual void Start() override;
			virtual void Stop() override;

			void SubscribeToChannel(EventSystem::EventChannel channel, std::shared_ptr<EventSystem::EventListener> eventListener);
			void PublishToChannel(EventSystem::EventChannel channel, EventSystem::EventData eventData);

		};
	}
}