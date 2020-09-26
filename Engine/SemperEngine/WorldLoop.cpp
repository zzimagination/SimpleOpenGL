#include "WorldLoop.h"
#include "WorldMap.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace SemperEngine
{
	namespace Core
	{
		void WorldLoop::BeforeLoop()
		{
			WorldMap::BuildWorld();
			WorldManager::Initialize();
			Once();
		}

		void WorldLoop::Loop()
		{
			Once();
		}

		void WorldLoop::AfterLoop()
		{
			auto fruits = WorldTree::worldFruits;
			WorldTree::worldFruits.clear();
			for (int i = 0; i < fruits.size(); i++)
			{
				auto fruit = fruits[i];
				if (fruit->bad)
				{
					continue;
				}
				WorldManager::currentWorld = fruit->world.get();
				fruit->container.EndGameObjects();
				fruit->action->End();
				delete fruit;
			}
			WorldManager::currentWorld = nullptr;
		}

		void WorldLoop::Once()
		{
			auto newFruits = WorldTree::newWorldFruits;
			WorldTree::newWorldFruits.clear();
			for (int i = 0; i < newFruits.size(); i++)
			{
				auto fruit = newFruits[i];
				if (fruit->bad)
				{
					continue;
				}
				WorldManager::currentWorld = fruit->world.get();
				fruit->action->Start();
				fruit->container.StartGameObjects();
				WorldTree::worldFruits.push_back(fruit);
			}
			WorldManager::currentWorld = nullptr;

			auto fruits = WorldTree::worldFruits;
			for (int i = 0; i < fruits.size(); i++)
			{
				auto fruit = fruits[i];
				if (fruit->bad)
				{
					continue;
				}
				WorldManager::currentWorld = fruit->world.get();
				fruit->container.StartGameObjects();
				fruit->action->Update();
				fruit->container.UpdateGameObjects();
			}
			WorldManager::currentWorld = nullptr;

			WorldManager::WorldAfterLoop();
			WorldTree::Fall();
		}
	}
}