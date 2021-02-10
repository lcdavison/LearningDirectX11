#pragma once

#include "EventListener.h"
#include "EventChannel.h"

#include <unordered_map>
#include <vector>

namespace RenderLibrary
{
	namespace EventSystem
	{
		class EventDispatcher
		{
			std::unordered_map<EventChannel, std::vector<EventListener>> eventChannels_;

		public:

		};
	}
}