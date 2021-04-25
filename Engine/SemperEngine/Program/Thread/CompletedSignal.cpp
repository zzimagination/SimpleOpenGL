#include "CompletedSignal.h"

namespace Semper
{
	using namespace std;

	CompletedSignal::CompletedSignal()
	{
	}
	CompletedSignal::~CompletedSignal()
	{
	}
	CompletedSignal::WaitCode CompletedSignal::Wait()
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
		_code = WaitCode::Normal;
	}

	void CompletedSignal::Send(WaitCode code)
	{
		unique_lock<mutex> locker(_mutex);
		_con.notify_one();
		_ready = true;
		_code = code;
	}
	void CompletedSignal::SendAll()
	{
		unique_lock<mutex> locker(_mutex);
		_con.notify_all();
		_ready = true;
		_code = WaitCode::Normal;
	}
	void CompletedSignal::SendAll(WaitCode code)
	{
		unique_lock<mutex> locker(_mutex);
		_con.notify_all();
		_ready = true;
		_code = code;
	}
}