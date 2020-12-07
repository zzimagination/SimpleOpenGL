#pragma once
#ifndef __GAMEOBJECT_CONTAINER__
#define __GAMEOBJECT_CONTAINER__

#include <vector>
#include <memory>
#include "Component.h"
#include "LifeContainer.h"

namespace SemperEngine
{
	namespace Core
	{
		class GameObjectContainer
		{
		private:

			std::vector<LifeContainer<Component>> _newComponents;

			std::vector<LifeContainer<Component>> _components;

		public:

			void AddComponent(LifeContainer<Component> com);

			void StartComponents();

			void UpdateComponents();

			void EndComponents();

		};
	}
}

#endif // !GAMEOBJECT_CONTAINTER
