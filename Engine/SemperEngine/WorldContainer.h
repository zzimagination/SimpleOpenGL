#pragma once
#ifndef __WORLD_CONTAINDER__
#define __WORLD_CONTAINDER__

#include <vector>
#include "GameObject.h"
#include "GameCabin.h"
#include "LifeContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldContainer
		{
		public:

			std::vector<GameCabin*> cabins;

			std::vector<GameCabin*> newCabins;

		public:

			WorldContainer();

			~WorldContainer();

			void Add(GameObject* gameObject);

			void Start();

			void Update();

			void End();

		};
	}
}

#endif // !WORLD_CONTAINDER
