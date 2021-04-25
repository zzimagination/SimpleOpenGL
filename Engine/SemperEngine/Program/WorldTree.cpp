#include "WorldTree.h"
#include "WorldManager.h"
#include "WorldMap.h"
#include "Debug.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

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
				fruit->container->Add(gameObjects[i]);
			}
			worldFruits.push_back(fruit);
		}

		void WorldTree::RemoveWorld(string name)
		{
			auto fruit = FindWorld(name);
			if (fruit->start)
			{
				EndOfWorld(fruit);
			}
			fruit->bad = true;
			_hasBad = true;
		}

		void WorldTree::RemoveWorld(int id)
		{
			auto fruit = FindWorld(id);
			if (fruit->start)
			{
				EndOfWorld(fruit);
			}
			fruit->bad = true;
			_hasBad = true;
		}

		vector<WorldFruit*> WorldTree::GetWorlds()
		{
			return worldFruits;
		}

		void WorldTree::ExcuteWorlds()
		{
			for (size_t i = 0; i < worldFruits.size(); i++)
			{
				auto fruit = worldFruits[i];
				if (fruit->bad)
				{
					continue;
				}
				ExcuteWorld(fruit);
			}
		}

		void WorldTree::EndWorlds()
		{
			for (int i = 0; i < worldFruits.size(); i++)
			{
				auto fruit = worldFruits[i];
				if (!fruit->bad)
				{
					EndOfWorld(fruit);
				}
				delete fruit;
			}
			WorldManager::currentWorld = "";
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
				newVector.push_back(fruit);
			}
			worldFruits = newVector;
			_hasBad = false;
		}

		WorldFruit* WorldTree::FindWorld(string name)
		{
			for (size_t i = 0; i < worldFruits.size(); i++)
			{
				if (worldFruits[i]->name == name)
				{
					return worldFruits[i];
				}
			}

			Debug::LogError({ "don't find the world ", name });
			return nullptr;
		}

		WorldFruit* WorldTree::FindWorld(int id)
		{
			for (size_t i = 0; i < worldFruits.size(); i++)
			{
				if (worldFruits[i]->id == id)
				{
					return worldFruits[i];
				}
			}

			Debug::LogError({ "don't find the world " , to_string(id) });
			return nullptr;
		}

		void WorldTree::ExcuteWorld(WorldFruit* fruit)
		{
			WorldManager::currentWorld = fruit->name;
			if (!fruit->start)
			{
				fruit->start = true;
				fruit->action->Start();
			}
			fruit->container->Start();
			fruit->action->Update();
			fruit->container->Update();
			WorldManager::currentWorld = "";
		}

		void WorldTree::EndOfWorld(WorldFruit* fruit)
		{
			WorldManager::currentWorld = fruit->name;
			fruit->container->End();
			fruit->action->End();
			WorldManager::currentWorld = "";
		}
	}
}