#pragma once
#include <vector>
#include "World.h"

class WorldManager
{
public:
 	static vector<World*> worlds;

	static World* active;
	
	static World* CreateWorld(string name);

	static void LiveWorld();
};

