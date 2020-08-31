#include "FrameRuntime.h"
#include "Time.h"

namespace SemperEngine {


	void FrameRuntime::BeginFrame()
	{
		Time::StartRecord();
	}


	void FrameRuntime::EndFrame()
	{
		Time::EndRecord();
	}
}