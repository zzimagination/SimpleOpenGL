#pragma once


#define FRAMERATE 60

 class FrameRuntime
{
public:
	static void BeginFrame();

	static void EndFrame();
private:
	static long lastClock_t;
};

