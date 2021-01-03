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
			WorldMap::Initialize();
			WorldManager::Initialize();
			WorldTree::ExcuteWorlds();
			WorldConverter::Convert();
			WorldTree::Fall();
		}

		void WorldLoop::Loop()
		{
			WorldTree::ExcuteWorlds();
			WorldConverter::Convert();
			WorldTree::Fall();
		}

		void WorldLoop::AfterLoop()
		{
			WorldTree::EndWorlds();
		}
	}
}