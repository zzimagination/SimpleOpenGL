#include "WorldManager.h"
#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldConverter.h"

namespace SemperEngine 
{
	namespace Core
	{
		using namespace std;
		using namespace Core;

		string WorldManager::currentWorld;

		string WorldManager::_active;

		string WorldManager::_inside;

		void WorldManager::Initialize()
		{
			_inside = WorldMap::WorldName(0);
			WorldMap::BuildWorld(0);
			_active = WorldMap::WorldName(1);
			WorldMap::BuildWorld(1);
		}

		string WorldManager::GetInside()
		{
			return _inside;
		}

		string WorldManager::GetActive()
		{
			return _active;
		}

		void WorldManager::SetActive(string name)
		{
			WorldConverter::SetNext(name);
		}

		void WorldManager::SetActive(int id)
		{
			WorldConverter::SetNext(id);
		}

		bool WorldManager::Inside()
		{
			return currentWorld == _inside;
		}
	}
}