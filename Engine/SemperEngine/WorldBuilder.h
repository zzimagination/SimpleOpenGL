#pragma once
#ifndef __WORLD_BUILDER__
#define __WORLD_BUILDER__

#include "GameObject.h"
#include "World.h"
#include "WorldAction.h"

namespace SemperEngine
{
	class WorldBuilder
	{
	public:

		std::string name;

		int id;

	private:

		WorldAction *_action;

		std::vector<GameObject*> _gameObjects;

	public:

		WorldBuilder(std::string name, int id)
		{
			this->name = name;
			this->id = id;
		}

		virtual World Build() = 0;

		std::vector<GameObject*> GetGameObjects()
		{
			auto temp = _gameObjects;
			_gameObjects.clear();
			return temp;
		}

		void AddGameObject(GameObject* gameObject)
		{
			_gameObjects.push_back(gameObject);
		}

		WorldAction* GetAction()
		{
			auto temp = _action;
			_action = nullptr;
			return temp;
		}

		void AddAction(WorldAction* action)
		{
			_action = action;
		}
	};
}

#endif // !WORLD_SPAWNER
