#pragma once
#ifndef WORLD_CONTAINDER
#define WORLD_CONTAINDER

#include <vector>
#include "GameObject.h"
#include "LifeContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldContainer
		{
		public:

			std::vector<LifeContainer<GameObject>> gameObjects;

			std::vector<LifeContainer<GameObject>> newGameObjects;

		public:

			WorldContainer();

			~WorldContainer();

			void AddGameObject(LifeContainer<GameObject> gameObject);

			void StartGameObjects();

			void UpdateGameObjects();

			void EndGameObjects();
		};
	}
}

#endif // !WORLD_CONTAINDER
