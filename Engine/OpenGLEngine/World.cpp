#include "World.h"
namespace SemperEngine {
	World::~World()
	{
		for (int i = 0; i < newGameObjects.size(); i++)
		{
			delete newGameObjects[i];
		}
		for (int i = 0; i < gameObjects.size(); i++)
		{
			delete gameObjects[i];
		}
	}

	void World::AddGameObject(GameObject * gameObject)
	{
		if (gameObject == nullptr)
		{
			throw "gameObject is null";
		}
		newGameObjects.push_back(gameObject);
	}

	void World::RemoveGameObject(GameObject * gameObject)
	{
		for (auto i = newGameObjects.begin(); i != newGameObjects.end(); i++)
		{
			if (*i == gameObject)
			{
				newGameObjects.erase(i);
				return;
			}
		}
		for (auto i = gameObjects.begin(); i != gameObjects.end(); i++)
		{
			if (*i == gameObject)
			{
				gameObjects.erase(i);
				return;
			}
		}
	}

	void World::Live()
	{
		for (int i = 0; i < newGameObjects.size(); i++)
		{
			newGameObjects[i]->Start();
			newGameObjects[i]->Start_Internal();
		}

		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update();
			gameObjects[i]->Update_Internal();
		}
		if (newGameObjects.size() == 0)
		{
			return;
		}
		gameObjects.assign(newGameObjects.begin(), newGameObjects.end());
		newGameObjects.clear();
	}
}