#pragma once
#ifndef SECOND_WORLD_ACTION
#define SECOND_WORLD_ACTION

#include "WorldAction.h"

namespace SemperEngine
{
	class SecondWorldAction :public WorldAction
	{
	public:

		SecondWorldAction(World world);

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !SECOND_WORLD_ACTION
