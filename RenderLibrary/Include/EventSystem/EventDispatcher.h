#pragma once

#include "EventListener.h"
#include "EventChannel.h"
#include "Services/Service.h"

#include <unordered_map>
#include <vector>
#include <memory>

namespace RenderLibrary
{
	namespace EventSystem
	{
		class EventDispatcher : public Services::Service
		{
			std::unordered_map<EventChannel, std::vector<std::shared_ptr<EventListener>>> eventChannels_;

		public:
			EventDispatcher();

			virtual void Start() override;
			virtual void Stop() override;

			void SubscribeToChannel(EventChannel channel, std::shared_ptr<EventListener> eventListener);
			void PublishToChannel(EventChannel channel);

		};
	}
}