#pragma once
#ifndef __GAMESLOT__
#define __GAMESLOT__

#include "Common.h"
#include "Component.h"

namespace Semper
{
	namespace Core
	{
		class GameSlot
		{
		public:

			Component* component = nullptr;

			LifeContainer<Component> componentLife;

		public:

			bool Dead();
		};
	}
}

#endif // !__GAMESLOT__
