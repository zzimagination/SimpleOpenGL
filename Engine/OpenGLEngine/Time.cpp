#include "Time.h"
#include <thread>
#include <iostream>
#include <Windows.h>

namespace SemperEngine {

	using namespace std;

	float Time::time = 0;

	float Time::deltaTime = 0;

	chrono::steady_clock::time_point Time::timePoint;

	float Time::GetTime() {
		return time;
	}

	float Time::GetDeltaTime() {
		return deltaTime;
	}

	void Time::StartRecord()
	{
		timePoint = chrono::steady_clock::now();
	}

	void Time::EndRecord()
	{
		auto current = chrono::steady_clock::now();
		auto interval = current - timePoint;
		deltaTime = (double)interval.count() / 1000000000;
		time += deltaTime;
	}
}