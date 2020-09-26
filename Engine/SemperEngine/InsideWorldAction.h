#pragma once
#ifndef INSIDE_WORLD_ACTION
#define INSIDE_WORLD_ACTION

#include "WorldAction.h"

namespace SemperEngine
{
	class InsideWorldAction : public WorldAction
	{
	public:

		int count;

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !INSIDE_WORLD_ACTION
