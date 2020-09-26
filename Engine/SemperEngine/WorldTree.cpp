#include "WorldTree.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<WorldFruit*> WorldTree::newWorldFruits;

		std::vector<WorldFruit*> WorldTree::worldFruits;

		World* WorldTree::AddWorld(World world, WorldAction* action)
		{
			WorldFruit* fruit = new WorldFruit();
			fruit->world.reset(new World(world));
			fruit->world->treeID = worldFruits.size() + newWorldFruits.size();
			fruit->action.reset(action);
			newWorldFruits.push_back(fruit);
			return fruit->world.get();
		}

		void WorldTree::RemoveWorld(World* world)
		{
			WorldFruit* fruit;
			if (world->treeID < worldFruits.size())
			{
				fruit = worldFruits[world->treeID];
			}
			else
			{
				fruit = newWorldFruits[world->treeID - worldFruits.size()];
			}
			fruit->container.EndGameObjects();
			fruit->action->End();
			fruit->bad = true;
		}

		WorldFruit* WorldTree::GetFruit(World* world)
		{
			WorldFruit* fruit;
			if (world->treeID < worldFruits.size())
			{
				fruit = worldFruits[world->treeID];
			}
			else
			{
				fruit = newWorldFruits[world->treeID - worldFruits.size()];
			}
			return fruit;
		}

		void WorldTree::Fall()
		{
			vector<WorldFruit*> newVector;
			for (int i = 0; i < worldFruits.size(); i++)
			{
				auto fruit = worldFruits[i];
				if (fruit->bad)
				{
					delete fruit;
					continue;
				}
				fruit->world->treeID = newVector.size();
				newVector.push_back(fruit);
			}
			worldFruits = newVector;
		}
	}
}