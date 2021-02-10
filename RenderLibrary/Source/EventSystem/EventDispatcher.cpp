#include "EventSystem/EventDispatcher.h"

namespace RenderLibrary
{
	namespace EventSystem
	{
		EventDispatcher::EventDispatcher()
		{
			serviceId = Services::ServiceID::EventDispatcher;
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

		void EventDispatcher::PublishToChannel(EventChannel channel)
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