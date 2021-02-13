#pragma once

#include <functional>
#include <memory>

#include "Events/Event.h"
#include "BaseEventHandler.h"

namespace RenderLibrary
{
	namespace EventSystem
	{
		template<class EventType>
		class EventHandler final : public BaseEventHandler
		{
			std::function<void(std::shared_ptr<EventType>)> eventFunction_;

		public:
			EventHandler(std::function<void(std::shared_ptr<EventType>)> eventFunction);

			virtual void operator ()(std::shared_ptr<Event> eventData) const override;

		};

		template<class EventType>
		EventHandler<EventType>::EventHandler(std::function<void(std::shared_ptr<EventType>)> eventFunction)
			: eventFunction_{eventFunction}
		{
		}

		template<class EventType>
		void EventHandler<EventType>::operator()(std::shared_ptr<Event> eventData) const
		{
			auto eventTypePointer = std::static_pointer_cast<EventType>(eventData);
			eventFunction_(eventTypePointer);
		}
	}
}