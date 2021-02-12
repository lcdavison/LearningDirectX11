#pragma once

#include "ServiceID.h"

namespace RenderLibrary
{
	namespace Services
	{
		class Service
		{
		protected:
			ServiceID serviceId = ServiceID::Unassigned;

		public:
			virtual void Start() = 0;
			virtual void Stop() = 0;

			ServiceID GetServiceID() const;
		};
	}
}