#ifndef EVENTSYSTEM
#define EVENTSYSTEM

#include "EventDef.h"

namespace SemperEngine {

	namespace Core
	{
		class EventManager
		{
		private:

			static float keepInterval;

		public:

			static void ProcessEvent();

			static void EndEvents();

		};
	}
}
#endif