#pragma once
#ifndef __WORLD_FRUIT__
#define __WORLD_FRUIT__

#include <memory>
#include "World.h"
#include "WorldAction.h"
#include "WorldContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldFruit
		{
		public:

			World world;

			std::unique_ptr<WorldAction> action;

			WorldContainer container;

			bool isStarted;

			bool bad;

		public:

			WorldFruit();

			~WorldFruit();
			
		};
	}
}

#endif // !WORLD_FRUIT
