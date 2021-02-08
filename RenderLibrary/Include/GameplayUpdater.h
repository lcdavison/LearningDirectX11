#pragma once

namespace RenderLibrary
{
	namespace Gameplay
	{
		class GameplayUpdater
		{
		public:
			virtual ~GameplayUpdater() = default;

			virtual void Update() = 0;
		};
	}
}