#pragma once
#ifndef __WORLD_TREE__
#define __WORLD_TREE__

#include <string>
#include <vector>
#include "WorldFruit.h"


namespace SemperEngine
{

	namespace Core
	{
		class WorldTree
		{
		public:

			static std::vector<WorldFruit*> newWorldFruits;

			static std::vector<WorldFruit*> worldFruits;

		private:

			static bool _hasBad;

		public:

			static void AddWorld(std::string name, int id, WorldAction* action, std::vector<GameObject*> gameObjects);

			static void RemoveWorld(std::string name);

			static void RemoveWorld(int id);

			static WorldContainer* FindContainer(std::string name);

			static void Fall();

		private:

			static WorldFruit* FindWorld(std::string name);

			static WorldFruit* FindWorld(int id);

		};
	}
}

#endif // !WORLD_TREE
