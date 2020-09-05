#include "World.h"
#include "Camera.h"
#include "GameObject.h"

namespace SemperEngine {

	using namespace std;

	World::World(string name)
	{
		if (name == "")
		{
			throw "NULL";
		}
		this->_name = name;
	}

	World::~World()
	{
		_startedList.Reset();
		while (true)
		{
			auto obj = _startedList.Next();
			if (obj == nullptr)
			{
				break;
			}
			delete obj;
		}
		_startedList.Clear();

		_noStartList.Reset();
		while (true)
		{
			auto obj = _noStartList.Next();
			if (obj == nullptr)
			{
				break;
			}
			delete obj;
		}
		_noStartList.Clear();
	}

	std::string World::Name()
	{
		return _name;
	}

	bool World::IsActive()
	{
		return _isActive;
	}

	void World::Active()
	{
		_isActive = true;
	}

	void World::UnActive()
	{
		_isActive = false;
	}

}