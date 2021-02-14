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
			std::unordered_map<std::size_t, std::vector<std::shared_ptr<EventSystem::BaseEventHandler>>> eventChannels_;

		public:
			EventDispatcher();

			virtual void Start() override;
			virtual void Stop() override;

			template<typename EventType>
			void SubscribeToEvent(std::shared_ptr<EventSystem::BaseEventHandler> eventHandler);

			template<typename EventType>
			void PublishEvent(std::shared_ptr<EventType> eventData);

		};

		template<class EventType>
		void EventDispatcher::SubscribeToEvent(std::shared_ptr<EventSystem::BaseEventHandler> eventHandler)
		{
			auto hashCode = typeid(EventType).hash_code();
			auto iterator = eventChannels_.find(hashCode);

			if (iterator != eventChannels_.end())
			{
				auto& handlers = iterator->second;
				handlers.push_back(eventHandler);
			}
			else
			{
				eventChannels_.insert({hashCode, { eventHandler }});
			}
		}

		template<class EventType>
		void EventDispatcher::PublishEvent(std::shared_ptr<EventType> eventData)
		{
			auto hashCode = typeid(EventType).hash_code();
			auto iterator = eventChannels_.find(hashCode);

			if (iterator != eventChannels_.end())
			{
				auto& handlers = iterator->second;

				for (auto handler : handlers)
				{
					(*handler)(eventData);
				}
			}
		}
	}
}