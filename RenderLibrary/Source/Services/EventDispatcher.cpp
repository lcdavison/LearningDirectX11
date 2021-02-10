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

		void EventDispatcher::SubscribeToChannel(EventChannel channel, std::shared_ptr<EventListener> eventListener)
		{
			auto iterator = eventChannels_.find(channel);

			if (iterator != eventChannels_.end())
			{
				auto& listeners = iterator->second;
				listeners.push_back(eventListener);
			}
			else
			{
				eventChannels_.insert({channel, { eventListener }});
			}
		}

		void EventDispatcher::PublishToChannel(EventChannel channel, EventData eventData)
		{
			auto iterator = eventChannels_.find(channel);

			if (iterator != eventChannels_.end())
			{
				auto& listeners = iterator->second;

				for (auto listener : listeners)
				{
					listener->Notify(channel);
				}
			}
		}
	}
}