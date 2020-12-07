#pragma once
#ifndef __RESOURCEOBJECT_MANAGER__
#define __RESOURCEOBJECT_MANAGER__

namespace SemperEngine
{
	namespace Core
	{
		class ResourceObjectManager
		{
		public:

			static void PreLoad();

			static void EndProcess();

			static void Dispose();
		};
	}
}

#endif // !__RESOURCEOBJECT_MANAGER__