#include "Time.h"
#include "TimeManager.h"

namespace SemperEngine 
{
	using namespace std;
	using namespace Core;

	float Time::GetTime() {
		return TimeManager::time;
	}

	float Time::GetDeltaTime() {
		return TimeManager::deltaTime;
	}
	std::string Time::SystemTime()
	{
		return TimeManager::Now();
	}
}