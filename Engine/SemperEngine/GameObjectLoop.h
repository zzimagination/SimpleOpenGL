#pragma once
#ifndef GAME_OBJECT_LOOP
#define GAME_OBJECT_LOOP

namespace SemperEngine
{
	namespace Core
	{
		class GameObjectLoop
		{
		public:

			static void BeforeLoop();

			static void Loop();
		};
	}
}

#endif // !GAME_OBJECT_LOOP
