#include "CompletedSignal.h"



void CompletedSignal::Wait()
{
	unique_lock<mutex> locker(_mutex);
	while (!_ready)
	{
		_con.wait(locker);
	}
	_ready = false;
}

void CompletedSignal::Send()
{
	unique_lock<mutex> locker(_mutex);
	_con.notify_one();
	_ready = true;
}
