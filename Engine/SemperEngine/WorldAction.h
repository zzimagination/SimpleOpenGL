#pragma once
#ifndef WORLD_ACTION
#define WORLD_ACTION

#include "World.h"

namespace SemperEngine
{

	class WorldAction
	{
	public:

		World world;

	public:

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !WORLD_ACTION
