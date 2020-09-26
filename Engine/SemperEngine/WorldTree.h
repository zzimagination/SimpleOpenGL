#pragma once
#ifndef WORLD_TREE
#define WORLD_TREE

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

		public:

			static World AddWorld(World world, WorldAction* action, std::vector<GameObject*> gameObjects);

			static void RemoveWorld(World world);

			static WorldFruit* GetFruit(World world);

			static void Fall();
		};
	}
}

#endif // !WORLD_TREE
