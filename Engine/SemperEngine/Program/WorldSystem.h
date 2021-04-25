#pragma once
#ifndef __WORLD_LOOP__
#define __WORLD_LOOP__

namespace Semper
{
	namespace Core
	{
		class WorldSystem
		{
		public:

			static void BeforeLoop();

			static void Loop();

			static void AfterLoop();

		};
	}
}

#endif // !WORLD_LOOP
