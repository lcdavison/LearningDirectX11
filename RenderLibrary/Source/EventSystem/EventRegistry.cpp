#include "EventSystem/EventRegistry.h"

namespace RenderLibrary
{
	namespace EventSystem
	{
		std::unordered_map<std::size_t, std::shared_ptr<Event>> EventRegistry::registry_;
	}
}