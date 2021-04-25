#pragma once
#ifndef __WORLD_FRUIT__
#define __WORLD_FRUIT__

#include <memory>
#include "WorldAction.h"
#include "WorldContainer.h"

namespace Semper
{
	namespace Core
	{
		class WorldFruit
		{
		public:

			std::string name;

			int id;

			std::unique_ptr<WorldAction> action;

			std::unique_ptr<WorldContainer> container;

			bool start = false;

			bool bad = false;

		public:

			WorldFruit();

			~WorldFruit();

		};
	}
}

#endif // !WORLD_FRUIT
