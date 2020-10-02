#include "World.h"
#include "Camera.h"
#include "GameObject.h"

namespace SemperEngine {

	using namespace std;

	World::World()
	{
		this->_name = "";
		this->_id = -1;
	}

	World::World(std::string name, int id)
	{
		if (name == "" || id < 0)
		{
			throw "arguments error";
		}
		this->_name = name;
		this->_id = id;
		this->treeIndex = std::shared_ptr<unsigned int>(new unsigned int(0));
	}

	World::~World()
	{
	}

	std::string World::Name()
	{
		if (_name == "")
		{
			throw "error world";
		}
		return _name;
	}

	int World::ID()
	{
		if (_id < 0)
		{
			throw "error world";
		}
		return _id;
	}

	bool World::operator==(const World & world)
	{
		bool result = this->_name == world._name;
		result &= this->_id == world._id;
		return result;
	}

	bool World::operator!=(const World & world)
	{
		return !(*this == world);
	}

}