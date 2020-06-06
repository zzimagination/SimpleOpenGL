#include <ctime>
#include <thread>
#include <Windows.h>
#include "Time.h"
#include "FrameRuntime.h"

long FrameRuntime::lastClock_t = 0;

void FrameRuntime::BeginFrame()
{
	long current = clock();
	long interval = current - lastClock_t;
	Time::deltaTime = interval / (float)CLOCKS_PER_SEC;
	Time::time += Time::deltaTime;
	lastClock_t = current;
}


void FrameRuntime::EndFrame()
{
	long end = clock();
	long interval = end - lastClock_t;
	long waitTime =  1000/FRAMERATE -interval;
	if (waitTime > 0)
	{
		Sleep(waitTime);
	}
}
