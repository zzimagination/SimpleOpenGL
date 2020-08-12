#ifndef GAMELOOP
#define GAMELOOP

#include "CompletedSignal.h"

class GameLoop
{
private:

	static bool isLooping;

	static CompletedSignal mainSignal;

	static CompletedSignal logicSignal;

public:

	static void BeforeLoop();

	static void MainLoop();

private:

	static void LogicLoop();
};

#endif // !GAMELOOP