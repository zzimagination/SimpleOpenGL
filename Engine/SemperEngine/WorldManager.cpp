#include "WorldManager.h"
namespace SemperEngine {
	vector<World*> WorldManager::worlds;

	World* WorldManager::_active = nullptr;

	bool WorldManager::_changeActive = false;

	int WorldManager::_changeActiveIndex = -1;

	World * WorldManager::CreateWorld(string name)
	{
		auto index = HasWorld(name);
		if (index >= 0)
		{
			return worlds[index];
		}

		World* w = new World();
		w->name = name;
		worlds.push_back(w);

		if (_active == nullptr)
		{
			_active = w;
			_active->Active();
		}
		return w;
	}

	void WorldManager::DestroyWorld(std::string name)
	{
		if (name == _active->name)
		{
			throw "don't destroy active world";
		}
		auto index = HasWorld(name);
		if (index < 0)
		{
			throw "doesn't have this world";
		}
		auto world = worlds[index];
		worlds.erase(worlds.begin() + index);
		delete world;
	}

	World * WorldManager::GetActive()
	{
		return _active;
	}

	void WorldManager::SetActive(string name)
	{
		auto index = HasWorld(name);
		if (index < 0)
		{
			throw "doesn't have this world";
		}
		if (name == _active->name)
		{
			_changeActive = false;
			_changeActiveIndex = -1;
			return;
		}
		_changeActive = true;
		_changeActiveIndex = index;
	}

	void WorldManager::UpdateWorld()
	{
		if (_changeActive)
		{
			_changeActive = false;
			_changeActiveIndex = -1;
			_active->UnActive();
			_active = worlds[_changeActiveIndex];
			_active->Active();
			return;
		}
		if (_active != nullptr)
		{
			_active->Update();
		}
	}

	int WorldManager::HasWorld(std::string name)
	{
		for (int i = 0; i < worlds.size(); i++)
		{
			if (worlds[i]->name == name)
			{
				return i;
			}
		}
		return -1;
	}
}