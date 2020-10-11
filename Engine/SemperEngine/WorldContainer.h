#pragma once
#ifndef __WORLD_CONTAINDER__
#define __WORLD_CONTAINDER__

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

		private:

			unsigned int DecodeWorldID(GameObject* gobject);

			void EncodeWorldID(GameObject* gobject, unsigned int i);
		};
	}
}

#endif // !WORLD_CONTAINDER
