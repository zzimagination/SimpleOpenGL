#include "WorldLoop.h"
#include "WorldMap.h"
#include "WorldManager.h"
#include "WorldTree.h"
#include "WorldConverter.h"

namespace SemperEngine
{
	namespace Core
	{
		void WorldLoop::BeforeLoop()
		{
			WorldMap::InitWorldBuilder();
			WorldManager::Initialize();
			Once();
			WorldConverter::Convert();
			WorldTree::Fall();
		}

		void WorldLoop::Loop()
		{
			Once();
			WorldTree::Fall();
			WorldConverter::Convert();
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
				WorldManager::currentWorld = &fruit->world;
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
				WorldManager::currentWorld = & fruit->world;
				fruit->action->Start();
				fruit->container.StartGameObjects();
				WorldTree::worldFruits.push_back(fruit);
			}

			auto fruits = WorldTree::worldFruits;
			for (int i = 0; i < fruits.size(); i++)
			{
				auto fruit = fruits[i];
				if (fruit->bad)
				{
					continue;
				}
				WorldManager::currentWorld = & fruit->world;
				fruit->container.StartGameObjects();
				fruit->action->Update();
				fruit->container.UpdateGameObjects();
			}

			WorldManager::currentWorld = nullptr;
		}
	}
}