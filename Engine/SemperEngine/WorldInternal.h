#pragma once
#ifndef WORLD_INTERNAL
#define WORLD_INTERNAL

#include "World.h"

namespace SemperEngine
{
	namespace Core
	{
		class WorldStorageCenter;

		class WorldInternal : public World
		{
		public:

			WorldInternal(std::string name);

			~WorldInternal();

			virtual void AddGameObject(GameObject * gameObject) override;
			
			virtual void RemoveGameObject(GameObject * gameObject) override;
			
		protected:

			virtual void Active() override;
			
			virtual void UnActive() override;
			
			virtual void Start() override;

			virtual void Update() override;

			virtual void End() override;

			friend class WorldStorageCenter;

		};
	}
}

#endif // !WORLD_INTERNAL
