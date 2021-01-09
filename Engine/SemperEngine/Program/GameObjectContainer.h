#pragma once
#ifndef __GAMEOBJECT_CONTAINER__
#define __GAMEOBJECT_CONTAINER__

#include <vector>
#include <memory>
#include <typeIndex>
#include "Component.h"
#include "Common.h"
#include "GameSlot.h"

namespace SemperEngine
{
	namespace Core
	{
		class GameObjectContainer
		{
		private:

			std::vector<GameSlot*> _newSlots;

			std::vector<GameSlot*> _slots;

		public:

			void AddComponent(Component* com);

			void Remove(std::type_index type);

			std::vector<Component*> GetComponents();
			
			Component* GetComponent(std::type_index type);

			void Start();

			void Update();

			void End();
		};
	}
}

#endif // !GAMEOBJECT_CONTAINTER
