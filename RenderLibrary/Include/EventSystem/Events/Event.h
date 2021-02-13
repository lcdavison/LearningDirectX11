#pragma once

#include "EventSystem/EventChannel.h"

namespace RenderLibrary
{
	namespace EventSystem
	{
		struct Event
		{
		protected:
			EventChannel channel;
		};
	}
}