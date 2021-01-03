#ifndef __GAME_LOOP__
#define __GAME_LOOP__

#include "CompletedSignal.h"

namespace SemperEngine {

	namespace Core
	{
		class GameLoop
		{
		private:

			static bool _isLooping;

			static CompletedSignal loopSignal;

			static CompletedSignal mainSignal;

			static CompletedSignal logicSignal;

		public:

			static void BeforeLoop();

			static void MainLoop();

			static void AfterLoop();

		private:

			static void LogicLoop();

			static bool IsExitLoop();
		};
	}
}
#endif // !GAMELOOP