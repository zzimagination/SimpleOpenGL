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
			EncodeTreeID(fruit->world, (unsigned int)(worldFruits.size() + newWorldFruits.size()));
			newWorldFruits.push_back(fruit);
			return fruit->world;
		}

		void WorldTree::RemoveWorld(World world)
		{
			WorldFruit* fruit;
			auto treeID = DecodeTreeID(world);
			if (treeID < worldFruits.size())
			{
				fruit = worldFruits[treeID];
			}
			else
			{
				fruit = newWorldFruits[treeID - worldFruits.size()];
			}
			fruit->container.EndGameObjects();
			fruit->action->End();
			fruit->bad = true;
		}

		WorldFruit* WorldTree::GetFruit(World world)
		{
			WorldFruit* fruit;
			auto treeID = DecodeTreeID(world);
			if (treeID < worldFruits.size())
			{
				fruit = worldFruits[treeID];
			}
			else
			{
				fruit = newWorldFruits[treeID - worldFruits.size()];
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
				EncodeTreeID(fruit->world, (unsigned int)newVector.size());
				newVector.push_back(fruit);
			}
			worldFruits = newVector;
		}

		unsigned int WorldTree::DecodeTreeID(World& w)
		{
			auto id = w.treeIndex1.ID() - 1;
			return id;
		}
		void WorldTree::EncodeTreeID(World& w, int i)
		{
			w.treeIndex1 = i + 1;
		}
	}
}