#pragma once
#ifndef __RESOURCEOBJECT_MANAGER__
#define __RESOURCEOBJECT_MANAGER__

namespace SemperEngine
{
	namespace Core
	{
		class ResourceSystem
		{
		public:

			static void Start();

			static void BeforeLoop();

			static void Loop();

			static void AfterLoop();

			static void EndProcess();

			static void DisposeUnused();
		};
	}
}

#endif // !__RESOURCEOBJECT_MANAGER__