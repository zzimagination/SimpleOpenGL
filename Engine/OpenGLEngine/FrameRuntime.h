#ifndef FRAMERUNTIME
#define FRAMERUNTIME

#include "EngineDef.h"

namespace SemperEngine {

	class FrameRuntime
	{
	public:
		static void BeginFrame();

		static void EndFrame();
	private:
		static long lastClock_t;
	};

}
#endif // !FRAMERUNTIME

