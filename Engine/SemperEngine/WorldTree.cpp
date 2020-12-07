#include "WorldTree.h"
#include "WorldManager.h"
#include "WorldMap.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<WorldFruit*> WorldTree::newWorldFruits;

		std::vector<WorldFruit*> WorldTree::worldFruits;

		bool WorldTree::_hasBad;

		void WorldTree::AddWorld(string name, int id, WorldAction* action, vector<GameObject*> gameObjects)
		{
			WorldFruit* fruit = new WorldFruit();
			fruit->name = name;
			fruit->id = id;
			fruit->action.reset(action);
			for (int i = 0; i < gameObjects.size(); i++)
			{
				fruit->container->AddGameObject(gameObjects[i]);
			}
			fruit->treeId = (int)(worldFruits.size() + newWorldFruits.size());
			newWorldFruits.push_back(fruit);
		}

		void WorldTree::RemoveWorld(string name)
		{
			auto fruit = FindWorld(name);
			fruit->container->EndGameObjects();
			fruit->action->End();
			fruit->bad = true;
			_hasBad = true;
		}

		void WorldTree::RemoveWorld(int id)
		{
			auto fruit = FindWorld(id);
			fruit->container->EndGameObjects();
			fruit->action->End();
			fruit->bad = true;
			_hasBad = true;
		}

		WorldContainer* WorldTree::FindContainer(std::string name)
		{
			return FindWorld(name)->container.get();
		}

		void WorldTree::Fall()
		{
			if (!_hasBad)
			{
				return;
			}
			vector<WorldFruit*> newVector;
			for (int i = 0; i < worldFruits.size(); i++)
			{
				auto fruit = worldFruits[i];
				if (fruit->bad)
				{
					delete fruit;
					continue;
				}
				fruit->treeId = (int)newVector.size();
				newVector.push_back(fruit);
			}
			for (int i = 0; i < newWorldFruits.size(); i++)
			{
				auto fruit = newWorldFruits[i];
				fruit->treeId = (int)newVector.size() + i;
			}
			worldFruits = newVector;
			_hasBad = false;
		}

		WorldFruit* WorldTree::FindWorld(string name)
		{
			for (int i = 0; i < newWorldFruits.size(); i++)
			{
				if (newWorldFruits[i]->name == name)
				{
					return newWorldFruits[i];
				}
			}
			for (int i = 0; i < worldFruits.size(); i++)
			{
				if (worldFruits[i]->name == name)
				{
					return worldFruits[i];
				}
			}
			string log = "don't find the world ";
			log.append(name);
			Debug::Log(log);
			throw log;
		}
		WorldFruit* WorldTree::FindWorld(int id)
		{
			for (int i = 0; i < newWorldFruits.size(); i++)
			{
				if (newWorldFruits[i]->id == id)
				{
					return newWorldFruits[i];

				}
			}
			for (int i = 0; i < worldFruits.size(); i++)
			{
				if (worldFruits[i]->id == id)
				{
					return worldFruits[i];
				}
			}
			string log = "don't find the world ";
			log.append(to_string(id));
			Debug::Log(log);
			throw log;
		}
	}
}