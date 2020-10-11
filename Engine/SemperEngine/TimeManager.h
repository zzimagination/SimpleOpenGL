#pragma once
#ifndef __TIME_MANAGER__
#define __TIME_MANAGER__

#include <ctime>
#include <thread>

namespace SemperEngine
{
	namespace Core
	{
		class TimeManager
		{
		public:

			static float time;

			static float deltaTime;

			static std::chrono::steady_clock::time_point timePoint;

		private:

			friend class FrameRuntime;

		public:

			static void StartRecord();

			static void EndRecord();
		};
	}
}

#endif // !TIME_MANAGER
