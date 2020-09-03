#ifndef WORLD_MANAGER
#define WORLD_MANAGER

#include <vector>

namespace SemperEngine {

	class World;

	class WorldManager
	{
	private:

	public:

		static World* GetActive();

		static World* Get(std::string name);

		static World* Get(int id);

		static void SetActive(std::string name);

		static void SetActive(int id);

		static void SetActive(World* world);
	};

}
#endif