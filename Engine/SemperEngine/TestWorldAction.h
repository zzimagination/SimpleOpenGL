#pragma once
#ifndef __TEST_WORLD_ACTION__
#define __TEST_WORLD_ACTION__

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class TestWorldAction : public WorldAction
	{
	public:

		virtual ~TestWorldAction() override;

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;
	};
}

#endif // !TEST_WORLD_ACTION
