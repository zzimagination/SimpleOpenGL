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

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !TEST_WORLD_ACTION
