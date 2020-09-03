#pragma once
#ifndef WORLD_INITIALIZER
#define WORLD_INITIALIZER

namespace SemperEngine
{

	namespace Core
	{
		class WorldInternal;

		class WorldInitializer
		{
		public:

			static void Initialize();

		private:

			static WorldInternal* CreateWorld_1();

			static WorldInternal* CreateWorld_2();

			static WorldInternal* CreateWorld_3();
		};
	}
}
#endif // !WORLD_INITIALIZER
