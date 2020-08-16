#ifndef WORLD_MANAGER
#define WORLD_MANAGER

#include <vector>
#include "World.h"
namespace SemperEngine {
	class WorldManager
	{
	public:
		static vector<World*> worlds;

		static World* active;

		static World* CreateWorld(string name);

		static void LiveWorld();
	};

}
#endif