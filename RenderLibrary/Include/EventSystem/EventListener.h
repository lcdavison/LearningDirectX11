#pragma once

#include "EventChannel.h"

namespace RenderLibrary
{
	namespace EventSystem
	{
		class EventListener
		{
		public:
			virtual void Notify(EventChannel channel) = 0;
		};
	}
}