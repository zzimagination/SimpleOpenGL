#include "WorldConverter.h"
#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		NextWorld WorldConverter::nextWorld;

		void WorldConverter::SetNext(std::string name)
		{
			auto id = WorldMap::GetWorldID(name);
			SetNext(id);
		}
		void WorldConverter::SetNext(int id)
		{
			if (!WorldMap::Contain(id))
			{
				throw "arguments error";
			}
			nextWorld.SetID(id);
		}
		void WorldConverter::Convert()
		{
			if (nextWorld.isChange)
			{
				auto last = WorldManager::GetActive();
				WorldTree::RemoveWorld(last);
				auto next = WorldMap::BuildWorld(nextWorld.GetID());
				WorldManager::_active = next;
				nextWorld.Reset();
			}
		}
	}
}