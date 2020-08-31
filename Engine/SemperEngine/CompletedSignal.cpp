#include "CompletedSignal.h"


namespace SemperEngine {
	WaitCode CompletedSignal::Wait()
	{
		unique_lock<mutex> locker(_mutex);
		while (!_ready)
		{
			_con.wait(locker);
		}
		_ready = false;
		return _code;
	}

	void CompletedSignal::Send()
	{
		unique_lock<mutex> locker(_mutex);
		_con.notify_one();
		_ready = true;
		_code = Normal;
	}

	void CompletedSignal::Send(WaitCode code)
	{
		unique_lock<mutex> locker(_mutex);
		_con.notify_one();
		_ready = true;
		_code = code;
	}
}