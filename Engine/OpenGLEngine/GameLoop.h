#pragma once

class GameLoop
{
private:

	static bool isLooping;

public:

	static void StartBeforeLoop();

	static void MainLoop();
};

