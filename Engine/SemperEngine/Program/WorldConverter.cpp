#include "WorldConverter.h"
#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldManager.h"
#include "Debug.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		NextWorld WorldConverter::nextWorld;

		void WorldConverter::SetNext(std::string name)
		{
			if (!WorldMap::Contain(name))
			{
				string log = "don't have the world ";
				log.append(name);
				Debug::Log(log);
				throw log;
			}
			nextWorld.SetID(WorldMap::WorldId(name));
		}
		void WorldConverter::SetNext(int id)
		{
			if (!WorldMap::Contain(id))
			{
				string log = "don't have the world ";
				log.append(to_string(id));
				Debug::Log(log);
				throw log;
			}
			nextWorld.SetID(id);
		}
		void WorldConverter::Convert()
		{
			if (nextWorld.isChange)
			{
				auto last = WorldManager::GetActive();
				WorldTree::RemoveWorld(last);
				WorldMap::BuildWorld(nextWorld.GetID());
				WorldManager::_active = WorldMap::WorldName(nextWorld.GetID());
				nextWorld.Reset();
			}
		}
	}
}