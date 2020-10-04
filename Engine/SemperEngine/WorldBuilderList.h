#pragma once
#ifndef WORLDBUILDLIST
#define WORLDBUILDLIST

#include <vector>
#include "TestWorld.h"
#include "InsideWorld.h"
#include "SecondWorld.h"

namespace SemperEngine 
{
	std::vector<WorldBuilder*> builders = {
		new InsideWorld(),
		new TestWorld(),
		new SecondWorld()
	};
}

#endif // !WORLDBUILDLIST