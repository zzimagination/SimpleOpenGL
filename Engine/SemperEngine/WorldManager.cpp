#include "WorldManager.h"
#include "WorldMap.h"
#include "WorldTree.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	World WorldManager::currentWorld;

	World WorldManager::_active;

	World WorldManager::_inside;

	NextWorld WorldManager::_next(1);

	void WorldManager::Initialize()
	{
		_inside = WorldMap::LoadWorld(0);
		_active = WorldMap::LoadWorld(1);
	}

	World WorldManager::GetInside()
	{
		return _inside;
	}

	World WorldManager::GetActive()
	{
		return _active;
	}

	void WorldManager::SetActive(string name)
	{
		auto id = WorldMap::GetWorldID(name);
		SetActive(id);
	}

	void WorldManager::SetActive(int id)
	{
		if (WorldMap::Contain(id))
		{
			_next.SetID(id);
		}
		else
		{
			throw "arguments error";
		}

	}

	void WorldManager::WorldAfterLoop()
	{
		if (_next.isChange)
		{
			WorldMap::UnloadWorld(_active);
			_active = WorldMap::LoadWorld(_next.GetID());
			_next.Reset();
		}
	}

}