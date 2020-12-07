#pragma once
#ifndef __DATACENTER_CLERK__
#define __DATACENTER_CLERK__

#include <string>
#include <memory>
#include "BaseData.h"

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

			void AddPath(std::string path);
		};
	}
}

#endif // !__DATACENTER_CLERK__
