#pragma once
#ifndef __WORLDBUILDLIST__
#define __WORLDBUILDLIST__

#include <vector>
#include "TestWorld.h"
#include "InsideWorld.h"
#include "SecondWorld.h"

namespace Semper 
{
	class WorldBuilderList
	{
	public:

		std::vector<WorldBuilder*> worldBuilders = {
			new TestWorld(),
			new SecondWorld(),
			new InsideWorld()
		};
	};
}

#endif // !WORLDBUILDLIST