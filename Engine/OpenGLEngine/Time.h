#ifndef TIME
#define TIME

#include <ctime>
#include <thread>
#include "EngineDef.h"

namespace SemperEngine {

	class Time
	{
	public:

		static float GetTime();

		static float GetDeltaTime();

	private:

		static float time;

		static float deltaTime;

		static std::chrono::steady_clock::time_point timePoint;

	private:

		friend class FrameRuntime;

	private:

		static void StartRecord();

		static void EndRecord();
	};

}

#endif // !TIME

