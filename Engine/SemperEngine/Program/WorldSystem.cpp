#include "WorldSystem.h"
#include "WorldMap.h"
#include "WorldManager.h"
#include "WorldTree.h"

namespace Semper
{
	namespace Core
	{
		void WorldSystem::BeforeLoop()
		{
			WorldMap::Initialize();
			WorldManager::Initialize();
		}

		void WorldSystem::Loop()
		{
			WorldTree::ExcuteWorlds();
			WorldManager::ConvertWorld();
			WorldTree::Fall();
		}

		void WorldSystem::AfterLoop()
		{
			WorldTree::EndWorlds();
		}
	}
}