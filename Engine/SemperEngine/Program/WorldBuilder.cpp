#include "WorldBuilder.h"
#include "Debug.h"

namespace Semper
{
	WorldBuilder::WorldBuilder(std::string name, int id)
	{
		this->name = name;
		this->id = id;
	}
	WorldBuilder::~WorldBuilder()
	{
	}
	std::vector<GameObject*> WorldBuilder::GetGameObjects()
	{
		auto temp = _gameObjects;
		_gameObjects.clear();
		return temp;
	}
	void WorldBuilder::AddGameObject(GameObject* gameObject)
	{
		_gameObjects.push_back(gameObject);
	}
	WorldAction* WorldBuilder::GetAction()
	{
		auto temp = _action;
		_action = nullptr;
		return temp;
	}
	void WorldBuilder::AddAction(WorldAction* action)
	{
		_action = action;
	}
}