#ifndef WORLD_MANAGER
#define WORLD_MANAGER

#include <vector>
#include "NextWorld.h"
#include "World.h"

namespace SemperEngine {

	class WorldManager
	{
	public:

		static World* currentWorld;

	private:

		static World* _active;

		static World* _inside;

		static Core::NextWorld _next;

	public:

		static void Initialize();

		static World* GetInside();

		static World* GetActive();

		static void SetActive(std::string name);

		static void SetActive(int id);

		static void WorldAfterLoop();

	};

}
#endif