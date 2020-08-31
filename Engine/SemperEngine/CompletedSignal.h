#ifndef COMPLETEDSIGNAL
#define COMPLETEDSIGNAL

#include <mutex>
#include <thread>
#include <condition_variable>

namespace SemperEngine {

	constexpr int Normal = 1;

	constexpr int Exit = 2;

	typedef int WaitCode;

	using namespace std;

	class CompletedSignal {

	public:

		WaitCode _code;

	private:

		condition_variable _con;

		mutex _mutex;

		bool _ready = false;

	public:

		WaitCode Wait();

		void Send();

		void Send(WaitCode code);
	};
}
#endif // !COMPLETEDSIGNAL
