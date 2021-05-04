#pragma once
#ifndef __WORLD_MAP__
#define __WORLD_MAP__

#include <map>
#include "WorldBuilder.h"

namespace Semper
{
	namespace Core
	{
		class WorldMap
		{
		public:

			static std::map<std::string, WorldBuilder*> builders;

			static std::string start;

			static std::string inside;

		public:

			static void Initialize();

			static void BuildWorld(std::string name);

			static bool Contain(std::string name);

		private:

			static WorldBuilder* GetBuilder(std::string name);

		};
	}
}

#endif // !WORLD_MAP
