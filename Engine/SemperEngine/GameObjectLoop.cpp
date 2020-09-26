#include "GameObjectLoop.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace SemperEngine
{
	namespace Core
	{
		void GameObjectLoop::BeforeLoop()
		{
			auto inside = WorldManager::GetInside();
			WorldManager::currentWorld = inside;
			auto insideFruit = WorldTree::GetFruit(inside);
			insideFruit->container.StartGameObjects();
			insideFruit->container.UpdateGameObjects();
			auto active = WorldManager::GetActive();
			WorldManager::currentWorld = active;
			auto activeFruit = WorldTree::GetFruit(active);
			activeFruit->container.StartGameObjects();
			activeFruit->container.UpdateGameObjects();
			WorldManager::currentWorld = nullptr;
		}

		void GameObjectLoop::Loop()
		{
			auto inside = WorldManager::GetInside();
			WorldManager::currentWorld = inside;
			auto insideFruit = WorldTree::GetFruit(inside);
			insideFruit->container.StartGameObjects();
			insideFruit->container.UpdateGameObjects();
			auto active = WorldManager::GetActive();
			WorldManager::currentWorld = active;
			auto activeFruit = WorldTree::GetFruit(active);
			activeFruit->container.StartGameObjects();
			activeFruit->container.UpdateGameObjects();
			WorldManager::currentWorld = nullptr;
		}
	}
}