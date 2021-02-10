#pragma once

#include <Windows.h>

#include "Service.h"

namespace RenderLibrary
{
	namespace Services
	{
		class TestService : public Service
		{
		public:
			TestService();

			virtual void Start() override;
			virtual void Stop() override;
		};
	}
}