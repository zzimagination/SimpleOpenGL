#include "WorldManager.h"
#include "WorldMap.h"
#include "WorldTree.h"
#include "WorldConverter.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	World WorldManager::currentWorld;

	World WorldManager::_active;

	World WorldManager::_inside;

	void WorldManager::Initialize()
	{
		_inside = WorldMap::BuildWorld(0);
		_active = WorldMap::BuildWorld(1);
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