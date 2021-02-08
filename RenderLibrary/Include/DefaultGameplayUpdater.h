#pragma once

#include "GameplayUpdater.h"

namespace RenderLibrary
{
	namespace Gameplay
	{
		class DefaultGameplayUpdater : public GameplayUpdater
		{
		public:
			DefaultGameplayUpdater();

			virtual void Update() override;
		};
	}
}