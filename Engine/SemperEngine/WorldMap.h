#pragma once
#ifndef WORLD_MAP
#define WORLD_MAP

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

			static void BuildWorld();

			static World* LoadWorld(int id );

			static World* LoadWorld(std::string id );

			static void UnloadWorld(World* world);

			static int GetWorldID(std::string name);

			static bool Contain(int id);

		private:

			static void AddBuilder(WorldBuilder* builder);

			static WorldBuilder* GetBuilder(int id);
		};
	}
}

#endif // !WORLD_MAP
