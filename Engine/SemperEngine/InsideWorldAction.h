#pragma once
#ifndef INSIDE_WORLD_ACTION
#define INSIDE_WORLD_ACTION

#include "WorldAction.h"

namespace SemperEngine
{
	class InsideWorldAction : public WorldAction
	{
	public:

		InsideWorldAction(World world);

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !INSIDE_WORLD_ACTION
