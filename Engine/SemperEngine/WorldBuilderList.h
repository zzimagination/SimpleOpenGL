#pragma once
#ifndef __WORLDBUILDLIST__
#define __WORLDBUILDLIST__

#include <vector>
#include "TestWorld.h"
#include "InsideWorld.h"
#include "SecondWorld.h"

namespace SemperEngine 
{
	std::vector<WorldBuilder*> worldBuilders = {
		new InsideWorld(),
		new TestWorld(),
		new SecondWorld()
	};
}

#endif // !WORLDBUILDLIST