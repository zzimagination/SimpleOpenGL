#ifndef TIME
#define TIME
namespace SemperEngine {

	class Time
	{
	public:
		static float GetTime();

		static float GetDeltaTime();

	private:
		static float time;

		static float deltaTime;

		friend class FrameRuntime;

	};

}

#endif // !TIME

