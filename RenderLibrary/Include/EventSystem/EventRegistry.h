#pragma once

#include "Events/Event.h"
#include "Exceptions/Exception.h"

#include <unordered_map>
#include <memory>

namespace RenderLibrary
{
	namespace EventSystem
	{
		class EventRegistry
		{
			static std::unordered_map<std::size_t, std::shared_ptr<Event>> registry_;

		public:

			template<class EventType>
			static void CreateAndRegisterEvent();

			template<class EventType>
			static EventType CloneEvent();
		};

		template<class EventType>
		void EventRegistry::CreateAndRegisterEvent()
		{
			auto hash = typeid(EventType).hash_code();
			auto eventPrototype = std::make_shared<EventType>();
			
			registry_.insert({hash, eventPrototype});
		}

		template<class EventType>
		EventType EventRegistry::CloneEvent()
		{
			auto hash = typeid(EventType).hash_code();
			auto iterator = registry_.find(hash);

			if (iterator != registry_.end())
			{
				auto prototype = std::static_pointer_cast<EventType>(iterator->second);
				auto clone = *(prototype);

				return clone;
			}
			else
			{
				throw Exception(L"Event prototype does not exist");
			}
		}
	}
}