#ifndef WORLD_MANAGER
#define WORLD_MANAGER

#include <vector>
#include "World.h"
namespace SemperEngine {
	class WorldManager
	{
	private:

		static World* _active;

		static bool _changeActive;

		static int _changeActiveIndex;

	public:
		static vector<World*> worlds;

		static World* CreateWorld(std::string name);

		static void DestroyWorld(std::string name);

		static World* GetActive();

		static void SetActive(std::string name);

		static void UpdateWorld();

	private:

		static int HasWorld(std::string name);
	};

}
#endif