#include "Time.h"

float Time::time = 0;

float Time::deltaTime = 0;

float Time::GetTime() {
	return time;
}

float Time::GetDeltaTime() {
	return deltaTime;
}