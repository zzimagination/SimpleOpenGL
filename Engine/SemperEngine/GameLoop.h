#ifndef GAMELOOP
#define GAMELOOP

#include "CompletedSignal.h"
namespace SemperEngine {
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

	private:

		static void LogicLoop();

		static bool ExitLoop();
	};
}
#endif // !GAMELOOP