#pragma once
#ifndef TEST_WORLD_ACTION
#define TEST_WORLD_ACTION

#include "WorldAction.h"
#include "GameObject.h"

namespace SemperEngine
{
	class TestWorldAction : public WorldAction
	{
	public:

		GameObject* mid;

	public:

		TestWorldAction(World world);

		virtual void Start();

		virtual void Update();

		virtual void End();
	};
}

#endif // !TEST_WORLD_ACTION
