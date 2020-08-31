#ifndef DEBUG_SYSTEM
#define DEBUG_SYSTEM
#include <thread>

namespace SemperEngine {

	class DebugSystem
	{
	private:

		static std::thread _debugThread;

		static bool _isOpen;

	public:

		static void Initialization();

		static void Dispose();

		static void Start();

		static void Update();
	};
}
#endif // !DEBUG_SYSTEM
