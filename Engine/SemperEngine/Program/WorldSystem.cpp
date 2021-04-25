#include "WorldSystem.h"
#include "WorldMap.h"
#include "WorldManager.h"
#include "WorldTree.h"
#include "WorldConverter.h"

namespace Semper
{
	namespace Core
	{
		void WorldSystem::BeforeLoop()
		{
			WorldMap::Initialize();
			WorldManager::Initialize();
			//WorldTree::ExcuteWorlds();
			//WorldConverter::Convert();
			WorldTree::Fall();
		}

		void WorldSystem::Loop()
		{
			WorldTree::ExcuteWorlds();
			WorldConverter::Convert();
			WorldTree::Fall();
		}

		void WorldSystem::AfterLoop()
		{
			WorldTree::EndWorlds();
		}
	}
}