#include "World.h"

World::~World()
{
	for	(int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}

void World::AddGameObject(GameObject * gameObject)
{
	gameObjects.push_back(gameObject);
}

void World::RemoveGameObject(GameObject * gameObject)
{
	for (auto i = gameObjects.begin(); i != gameObjects.end(); i++)
	{
		if (*i == gameObject)
		{
			gameObjects.erase(i);
		}
	}
}

void World::Live()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		CheckingGameObject(gameObjects[i]);
	}
}

void World::CheckingGameObject(GameObject* gameObject)
{
	if (!gameObject->_isStart)
	{
		gameObject->_isStart = true;
		gameObject->Start();
		gameObject->Start_Internal();
		return;
	}

	gameObject->Update();
	gameObject->Update_Internal();
}
