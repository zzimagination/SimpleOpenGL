#include "WorldContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		WorldContainer::WorldContainer()
		{
		}
		WorldContainer::~WorldContainer()
		{
		}
		void WorldContainer::AddGameObject(LifeContainer<GameObject> gameObject)
		{
			unsigned int id = newGameObjects.size() + gameObjects.size();
			*gameObject.id = id;
			newGameObjects.push_back(gameObject);
		}

		void WorldContainer::StartGameObjects()
		{
			auto tempNew = newGameObjects;
			newGameObjects.clear();
			for (int i = 0; i < tempNew.size(); i++)
			{
				auto gameObject = tempNew[i];
				if (!*gameObject.life)
				{
					continue;
				}
				gameObject.self->Start();
				gameObject.self->container.StartComponents();
				gameObjects.push_back(gameObject);
			}
		}

		void WorldContainer::UpdateGameObjects()
		{
			for (int i = 0; i < gameObjects.size(); i++)
			{
				auto gameObject = gameObjects[i];
				if (!*gameObject.life)
				{
					continue;
				}
				gameObject.self->Update();
				gameObject.self->container.UpdateComponents();
			}

			std::vector<LifeContainer<GameObject>> nextGameObjects;
			for (int i = 0; i < gameObjects.size(); i++)
			{
				auto gameObject = gameObjects[i];
				if (!*gameObject.life)
				{
					continue;
				}
				*gameObject.id = nextGameObjects.size();
				nextGameObjects.push_back(gameObject);
			}
			gameObjects = nextGameObjects;
		}

		void WorldContainer::EndGameObjects()
		{
			for (int i = 0; i < gameObjects.size(); i++)
			{
				auto gameObject = gameObjects[i];
				gameObject.self->container.EndComponents();
				gameObject.self->End();
				delete gameObject.self;
			}
		}
	}
}