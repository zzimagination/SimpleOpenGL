#ifndef __TIME_SCRIPT__
#define __TIME_SCRIPT__

#include <string>

namespace SemperEngine 
{
	class Time
	{
	public:

		static float GetTime();

		static float GetDeltaTime();

		static std::string SystemTime();
	};
}

#endif // !TIME

