#pragma once
#ifndef __WORLD_TREE__
#define __WORLD_TREE__

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

		private:

			static unsigned int DecodeTreeID(World& w);

			static void EncodeTreeID(World &w, int i);
		};
	}
}

#endif // !WORLD_TREE
