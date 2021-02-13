#pragma once

#include "Events/Event.h"

#include <memory>

namespace RenderLibrary
{
	namespace EventSystem
	{
		class BaseEventHandler
		{
		public:
			virtual void operator()(std::shared_ptr<Event> eventData) const = 0;
		};
	}
}