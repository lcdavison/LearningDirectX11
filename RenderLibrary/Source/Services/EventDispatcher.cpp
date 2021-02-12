#include "Services/EventDispatcher.h"

using namespace RenderLibrary::EventSystem;

namespace RenderLibrary
{
	namespace Services
	{
		EventDispatcher::EventDispatcher()
		{
			serviceId = ServiceID::EventDispatcher;
		}

		void EventDispatcher::Start()
		{
		}

		void EventDispatcher::Stop()
		{
		}

		void EventDispatcher::SubscribeToChannel(EventChannel channel, std::shared_ptr<BaseEventHandler> eventHandler)
		{
			auto iterator = eventChannels_.find(channel);

			if (iterator != eventChannels_.end())
			{
				auto& handlers = iterator->second;
				handlers.push_back(eventHandler);
			}
			else
			{
				eventChannels_.insert({channel, { eventHandler }});
			}
		}

		void EventDispatcher::PublishToChannel(EventChannel channel, std::shared_ptr<Event> eventData)
		{
			auto iterator = eventChannels_.find(channel);

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