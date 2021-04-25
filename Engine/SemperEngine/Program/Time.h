#ifndef __TIME_SCRIPT__
#define __TIME_SCRIPT__

#include <string>

namespace Semper 
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

