#ifndef __COMPLETEDSIGNAL__
#define __COMPLETEDSIGNAL__

#include <mutex>
#include <thread>
#include <condition_variable>

namespace Semper
{
	class CompletedSignal 
	{
	public:

		enum class WaitCode
		{
			Normal = 1,
			Exit = 2
		};

	public:

		WaitCode _code = WaitCode::Normal;

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
#endif // !COMPLETEDSIGNAL
