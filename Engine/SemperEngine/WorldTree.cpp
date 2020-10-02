#include "WorldTree.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<WorldFruit*> WorldTree::newWorldFruits;

		std::vector<WorldFruit*> WorldTree::worldFruits;

		World WorldTree::AddWorld(World world, WorldAction* action, vector<GameObject*> gameObjects)
		{
			WorldFruit* fruit = new WorldFruit();
			fruit->world = world;
			fruit->action.reset(action);
			for (int i = 0; i < gameObjects.size(); i++)
			{
				fruit->container.AddGameObject(gameObjects[i]);
			}
			unsigned int id = (unsigned int)(worldFruits.size() + newWorldFruits.size() + 1);
			*fruit->world.treeIndex = id;
			newWorldFruits.push_back(fruit);
			return fruit->world;
		}

		void WorldTree::RemoveWorld(World world)
		{
			WorldFruit* fruit;
			auto treeId = *world.treeIndex - 1;
			if (treeId < worldFruits.size())
			{
				fruit = worldFruits[treeId];
			}
			else
			{
				fruit = newWorldFruits[treeId - worldFruits.size()];
			}
			fruit->container.EndGameObjects();
			fruit->action->End();
			fruit->bad = true;
		}

		WorldFruit* WorldTree::GetFruit(World world)
		{
			WorldFruit* fruit;
			auto treeId = *world.treeIndex - 1;
			if (treeId < worldFruits.size())
			{
				fruit = worldFruits[treeId];
			}
			else
			{
				fruit = newWorldFruits[treeId - worldFruits.size()];
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
				*fruit->world.treeIndex = (unsigned int)newVector.size() + 1;
				newVector.push_back(fruit);
			}
			worldFruits = newVector;
		}
	}
}