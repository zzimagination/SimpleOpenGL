#pragma once
#ifndef __DATACENTER_CLERK__
#define __DATACENTER_CLERK__

#include <string>
#include <memory>
#include "Common.h"

namespace SemperEngine
{
	namespace Core
	{
		class DataCenterBase;

		class DataCenterClerk
		{
		public:

			int id;

			DataCenterBase* dataCenter;

		public:

			void Destroy();
		};
	}
}

#endif // !__DATACENTER_CLERK__
