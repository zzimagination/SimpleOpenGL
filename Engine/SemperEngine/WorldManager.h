#ifndef __WORLD_MANAGER__
#define __WORLD_MANAGER__

#include <vector>
#include "World.h"

namespace SemperEngine 
{

	namespace Core 
	{
		class WorldConverter;
	}

	class WorldManager
	{
	public:

		static World currentWorld;

	private:

		static World _active;

		static World _inside;

	public:

		static void Initialize();

		static World GetInside();

		static World GetActive();

		static void SetActive(std::string name);

		static void SetActive(int id);

		static bool Inside();

		friend class Core::WorldConverter;
	};

}
#endif