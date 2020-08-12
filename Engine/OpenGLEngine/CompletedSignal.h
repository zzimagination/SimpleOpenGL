#ifndef COMPLETEDSIGNAL
#define COMPLETEDSIGNAL

#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

class CompletedSignal {

private:

	condition_variable _con;

	mutex _mutex;

	bool _ready;

public:

	void Wait();

	void Send();
};

#endif // !COMPLETEDSIGNAL
