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
		_nostartGameObjects.Reset();
		while (true)
		{
			auto obj = _nostartGameObjects.Next();
			if (obj == nullptr)
			{
				break;
			}
			delete obj;
		}
	}

	vector<GameObject*> World::GameObjectList()
	{
		return _gameObjectList;
	}

	std::string World::Name()
	{
		return _name;
	}

}