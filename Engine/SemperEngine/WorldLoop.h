#pragma once
#ifndef WORLD_LOOP
#define WORLD_LOOP

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
