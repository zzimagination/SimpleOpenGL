#pragma once
#ifndef __GAMECABIN__
#define __GAMECABIN__

#include "Common.h"
#include "GameObject.h"
#include "GameObjectContainer.h"

namespace Semper
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
