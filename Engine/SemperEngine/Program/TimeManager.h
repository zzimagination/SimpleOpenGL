#pragma once
#ifndef __TIME_MANAGER__
#define __TIME_MANAGER__

#include <string>
#include <ctime>
#include <chrono>

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

			friend class FrameManager;

		public:

			static void StartRecord();

			static void EndRecord();

			static std::string Now();
		};
	}
}

#endif // !TIME_MANAGER
