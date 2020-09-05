#pragma once
#ifndef WORLD_INITIALIZER
#define WORLD_INITIALIZER

namespace SemperEngine
{

	namespace Core
	{
		class WorldInstance;

		class WorldInitializer
		{
		public:

			static void Initialize();

		private:

			static WorldInstance* CreateWorld_1();

			static WorldInstance* CreateWorld_2();

			static WorldInstance* CreateWorld_3();
		};
	}
}
#endif // !WORLD_INITIALIZER
