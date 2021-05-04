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

		std::string start = "First";

		std::string inside = "Inside";

		std::map<std::string, WorldBuilder*> GenerateBuilders()
		{
			std::map<std::string, WorldBuilder*> builders;
			builders["First"] = new TestWorld();
			builders["Second"] = new SecondWorld();
			builders["Inside"] = new InsideWorld();
			return builders;
		}
	};
}

#endif // !WORLDBUILDLIST