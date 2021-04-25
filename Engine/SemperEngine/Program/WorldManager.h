#ifndef __WORLD_MANAGER__
#define __WORLD_MANAGER__

#include <vector>
#include <string>

namespace Semper
{
	namespace Core
	{
		class WorldConverter;

		class WorldManager
		{
		public:

			static std::string currentWorld;

		private:

			static std::string _active;

			static std::string _inside;

		public:

			static void Initialize();

			static void ExcuteWorlds();

			static void EndWorlds();

			static std::string GetInside();

			static std::string GetActive();

			static void SetActive(std::string name);

			static void SetActive(int id);

			static bool Inside();

			friend class WorldConverter;
		};
	}
}
#endif