#ifndef __COMPLETEDSIGNAL__
#define __COMPLETEDSIGNAL__

#include <mutex>
#include <thread>
#include <condition_variable>

namespace SemperEngine
{
	namespace Core
	{
		constexpr int Normal = 1;

		constexpr int Exit = 2;

		typedef int WaitCode;

		class CompletedSignal {

		public:

			WaitCode _code;

		private:

			std::condition_variable _con;

			std::mutex _mutex;

			bool _ready = false;

		public:

			CompletedSignal();

			~CompletedSignal();

			WaitCode Wait();

			void Send();

			void Send(WaitCode code);

			void SendAll();

			void SendAll(WaitCode code);
		};
	}
}
#endif // !COMPLETEDSIGNAL
