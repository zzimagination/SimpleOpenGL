#include "WorldManager.h"
#include "WorldMap.h"
#include "WorldTree.h"

#include "Debug.h"

namespace Semper 
{
	namespace Core
	{
		using namespace std;
		using namespace Core;

		string WorldManager::currentWorld;

		string WorldManager::_active;

		string WorldManager::_inside;

		string WorldManager::_next;

		string WorldManager::_primitive;

		bool WorldManager::_changed;

		void WorldManager::Initialize()
		{
			WorldMap::BuildWorld(WorldMap::inside);
			WorldMap::BuildWorld(WorldMap::start);
			_inside = WorldMap::inside;
			_active = WorldMap::start;
		}

		void WorldManager::ConvertWorld()
		{
			if (!_changed)
			{
				return;
			}

			auto last = WorldManager::GetActive();
			WorldTree::RemoveWorld(last);
			WorldMap::BuildWorld(_next);
			WorldManager::_active = _next;
			_primitive = _next;
			_next = "";
		}

		string WorldManager::GetInside()
		{
			return _inside;
		}

		string WorldManager::GetActive()
		{
			return _active;
		}

		bool WorldManager::Inside()
		{
			return currentWorld == _inside;
		}

		void WorldManager::SetNextWorld(string name)
		{
			if (name == "")
			{
				Debug::LogError("world name don`t be null");
				return;
			}
			if (!WorldMap::Contain(name))
			{
				Debug::LogError({ "don't have the world " , name });
				return;
			}
			if (_next == name)
			{
				return;
			}
			if (_primitive == name)
			{
				return;
			}
			_next = name;
		}
	}
}