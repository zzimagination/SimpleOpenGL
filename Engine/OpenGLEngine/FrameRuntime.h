#pragma once

 class FrameRuntime
{
public:
	static void BeginFrame();
private:
	static long lastClock_t;
};

