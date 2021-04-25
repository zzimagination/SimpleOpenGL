#pragma once
#ifndef __TEST_WORLD__
#define __TEST_WORLD__

#include "WorldBuilder.h"

namespace Semper
{
	class TestWorld : public WorldBuilder
	{
	public:

		TestWorld();

		virtual void Build() override;

	};
}

#endif // !TEST_WORLD
