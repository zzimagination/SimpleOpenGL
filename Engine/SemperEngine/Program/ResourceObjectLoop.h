#pragma once
#ifndef __RESOURCEOBJECT_MANAGER__
#define __RESOURCEOBJECT_MANAGER__

namespace SemperEngine
{
	namespace Core
	{
		class ResourceObjectLoop
		{
		public:

			static void Start();

			static void BeforeLoop();

			static void Loop();

			static void AfterLoop();

		};
	}
}

#endif // !__RESOURCEOBJECT_MANAGER__