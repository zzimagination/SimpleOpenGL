#pragma once
#ifndef TEST_WORLD
#define TEST_WORLD

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
