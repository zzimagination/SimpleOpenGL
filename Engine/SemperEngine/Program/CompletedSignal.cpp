#include "CompletedSignal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		CompletedSignal::CompletedSignal()
		{
			_code = 0;
		}
		CompletedSignal::~CompletedSignal()
		{
		}
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
		void CompletedSignal::SendAll()
		{
			unique_lock<mutex> locker(_mutex);
			_con.notify_all();
			_ready = true;
			_code = Normal;
		}
		void CompletedSignal::SendAll(WaitCode code)
		{
			unique_lock<mutex> locker(_mutex);
			_con.notify_all();
			_ready = true;
			_code = code;
		}
	}
}