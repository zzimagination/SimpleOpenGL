#pragma once
#ifndef WORLD_INTERNAL
#define WORLD_INTERNAL

#include "World.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldStorageCenter;

		class WorldInstance : public World
		{
		protected:

			bool _isStart;

		public:

			WorldInstance(std::string name);

			~WorldInstance();

			virtual void AddGameObject(GameObject * gameObject) override;
			
			virtual void RemoveGameObject(GameObject * gameObject) override;
			
		protected:

			virtual void Start() override;

			virtual void Update() override;

			virtual void End() override;

			friend class WorldStorageCenter;

		};
	}
}

#endif // !WORLD_INTERNAL
