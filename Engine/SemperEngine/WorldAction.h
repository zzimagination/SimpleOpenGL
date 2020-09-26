#pragma once
#ifndef WORLD_ACTION
#define WORLD_ACTION

#include "World.h"

namespace SemperEngine
{

	class WorldAction
	{
	protected:

		World _world;

	public:

		WorldAction(World world);

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !WORLD_ACTION
