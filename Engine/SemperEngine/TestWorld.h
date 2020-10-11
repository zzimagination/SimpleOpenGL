#pragma once
#ifndef __TEST_WORLD__
#define __TEST_WORLD__

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class TestWorld : public WorldBuilder
	{
	public:

		TestWorld();

		virtual World Build() override;

	};
}

#endif // !TEST_WORLD
