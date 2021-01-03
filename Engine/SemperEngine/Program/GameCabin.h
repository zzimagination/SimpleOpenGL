#pragma once
#ifndef __GAMECABIN__
#define __GAMECABIN__

#include "LifeContainer.h"
#include "GameObject.h"
#include "GameObjectContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		class GameCabin
		{
		public:

			GameObject* gameObject = nullptr;

			LifeContainer<GameObject> objectLife;

		public:

			GameCabin();

			~GameCabin();

			bool Dead();
		};
	}
}

#endif // !__GAMECABIN__
