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
			fruit->world.treeIndex.reset(new unsigned int(worldFruits.size() + newWorldFruits.size()));
			fruit->action.reset(action);
			fruit->action->world = fruit->world;
			for (int i = 0; i < gameObjects.size(); i++)
			{
				fruit->container.AddGameObject(gameObjects[i]);
			}

			newWorldFruits.push_back(fruit);
			return fruit->world;
		}

		void WorldTree::RemoveWorld(World world)
		{
			WorldFruit* fruit;
			if ( *world.treeIndex < worldFruits.size())
			{
				fruit = worldFruits[*world.treeIndex];
			}
			else
			{
				fruit = newWorldFruits[*world.treeIndex - worldFruits.size()];
			}
			fruit->container.EndGameObjects();
			fruit->action->End();
			fruit->bad = true;
		}

		WorldFruit* WorldTree::GetFruit(World world)
		{
			WorldFruit* fruit;
			if (*world.treeIndex < worldFruits.size())
			{
				fruit = worldFruits[*world.treeIndex];
			}
			else
			{
				fruit = newWorldFruits[*world.treeIndex - worldFruits.size()];
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
				*fruit->world.treeIndex = newVector.size();
				newVector.push_back(fruit);
			}
			worldFruits = newVector;
		}
	}
}