#pragma once

class GameLoop
{
private:

	static bool isLooping;

public:

	static void BeforeLoop();

	static void MainLoop();
};

