#pragma once

#include "Event.h"

namespace RenderLibrary
{
	namespace EventSystem
	{
		struct WindowEvent final : public Event
		{
			int NewWidth;
			int NewHeight;

			bool HasWindowClosed;

			WindowEvent()
			{
				channel = EventChannel::Window;
			}

			WindowEvent(bool hasWindowClosed, int newWidth, int newHeight)
				: HasWindowClosed(hasWindowClosed),
				NewWidth(newWidth),
				NewHeight(newHeight)
			{
				channel = EventChannel::Window;
			}
		};
	}
}