#include "WorldManager.h"

vector<World*> WorldManager::worlds;

World* WorldManager::active;

World * WorldManager::CreateWorld(string name)
{
	for (int i = 0; i < worlds.size(); i++)
	{
		if (worlds[i]->name == name)
		{
			throw "had same name world";
		}
	}
	
	World* w = new World();
	worlds.push_back(w);
	active = w;
	return w;
}

void WorldManager::LiveWorld()
{
	if (active != nullptr)
	{
		active->Live();
	}
}
