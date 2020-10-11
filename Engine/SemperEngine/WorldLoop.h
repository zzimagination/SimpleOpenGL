#pragma once
#ifndef __WORLD_LOOP__
#define __WORLD_LOOP__

namespace SemperEngine
{
	namespace Core
	{
		class WorldLoop
		{
		public:

			static void BeforeLoop();

			static void Loop();

			static void AfterLoop();

		private:

			static void Once();
		};
	}
}

#endif // !WORLD_LOOP
