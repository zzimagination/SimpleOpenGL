#pragma once
#ifndef __WORLD_MAP__
#define __WORLD_MAP__

#include "World.h"
#include "WorldBuilder.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldMap
		{
		private:

			static std::vector<WorldBuilder*> _builders;

		public:

			static void InitWorldBuilder();

			static World BuildWorld(int id );

			static World BuildWorld(std::string id );

			static int GetWorldID(std::string name);

			static bool Contain(int id);

		private:

			static void AddBuilder(WorldBuilder* builder);

			static WorldBuilder* GetBuilder(int id);
		};
	}
}

#endif // !WORLD_MAP
