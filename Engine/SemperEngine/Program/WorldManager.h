#ifndef __WORLD_MANAGER__
#define __WORLD_MANAGER__

#include <vector>
#include <string>

namespace Semper
{
	namespace Core
	{
		class WorldManager
		{
		public:

			static std::string currentWorld;

		private:

			static std::string _active;

			static std::string _inside;

			static std::string _next;

			static std::string _primitive;

			static bool _changed;

		public:

			static void Initialize();

			static void ConvertWorld();

			static std::string GetInside();

			static std::string GetActive();

			static void SetNextWorld(std::string key);

			static bool Inside();
		};
	}
}
#endif