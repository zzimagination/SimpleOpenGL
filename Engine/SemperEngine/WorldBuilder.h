#pragma once
#ifndef __WORLD_BUILDER__
#define __WORLD_BUILDER__

#include <memory>
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

		WorldBuilder(std::string name, int id);

		virtual ~WorldBuilder();

		virtual void Build() = 0;

		std::vector<GameObject*> GetGameObjects();

		WorldAction* GetAction();

	protected:

		void AddGameObject(GameObject* gameObject);

		void AddAction(WorldAction* action);

	};
}

#endif // !WORLD_SPAWNER
