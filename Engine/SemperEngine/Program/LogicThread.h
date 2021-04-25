#pragma once
#ifndef __LOGICTHREAD__
#define __LOGICTHREAD__

#include <thread>
#include "GameThread.h"

namespace Semper
{
	namespace Core
	{
		class LogicThread : public GameThread
		{
		private:

			std::thread _thead;

		public:

			void Start();

			void Close();

			void WaitComplete();

			void Loop(bool goOn);
		};
	}
}

#endif // !__LOGICTHREAD__
