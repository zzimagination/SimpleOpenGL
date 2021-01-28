#ifndef __EVENT_MANAGER__
#define __EVENT_MANAGER__

namespace SemperEngine
{
	namespace Core
	{
		class EventSystem
		{
		public:

			static float keepInterval;

		public:

			static void ProcessEvent();

			static void EndEvents();

		};
	}
}
#endif