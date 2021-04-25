#pragma once
#ifndef __TEST_WORLD_ACTION__
#define __TEST_WORLD_ACTION__

#include <memory>
#include <vector>
#include "WorldAction.h"
#include "GameObject.h"

namespace Semper
{
	class TestWorldAction : public WorldAction
	{
	public:

		float y = 0;

		std::vector<GameObject*> objects;

	public:

		virtual ~TestWorldAction() override;

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !TEST_WORLD_ACTION
