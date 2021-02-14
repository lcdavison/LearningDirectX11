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
	}
}