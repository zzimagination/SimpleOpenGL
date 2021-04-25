#pragma once
#ifndef __WORLD_TREE__
#define __WORLD_TREE__

#include <string>
#include <vector>
#include "WorldFruit.h"


namespace Semper
{

	namespace Core
	{
		class WorldTree
		{
		public:

			static std::vector<WorldFruit*> worldFruits;

		private:

			static bool _hasBad;

		public:

			static void AddWorld(std::string name, int id, WorldAction* action, std::vector<GameObject*> gameObjects);

			static void RemoveWorld(std::string name);

			static void RemoveWorld(int id);

			static WorldFruit* FindWorld(std::string name);

		public:

			static void ExcuteWorlds();

			static void EndWorlds();

			static void Fall();

		private:

			static std::vector<WorldFruit*> GetWorlds();

			static WorldFruit* FindWorld(int id);

			static void ExcuteWorld(WorldFruit* fruit);

			static void EndOfWorld(WorldFruit* fruit);

		};
	}
}

#endif // !WORLD_TREE
