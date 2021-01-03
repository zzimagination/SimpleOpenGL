#include "TimeManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace chrono;

		float TimeManager::time = 0;

		float TimeManager::deltaTime = 0;

		chrono::steady_clock::time_point TimeManager::timePoint;

		void TimeManager::StartRecord()
		{
			timePoint = chrono::steady_clock::now();
		}

		void TimeManager::EndRecord()
		{
			auto current = chrono::steady_clock::now();
			auto interval = current - timePoint;
			deltaTime = (float)interval.count() / 1000000000;
			time += deltaTime;
		}

		string TimeManager::Now()
		{
			auto n = system_clock::now();
			auto time = system_clock::to_time_t(n);
			auto tm = localtime(&time);
			char* tstr = new char[20];
			strftime(tstr, 20, "%T", tm);
			return string(tstr);
		}
	}
}