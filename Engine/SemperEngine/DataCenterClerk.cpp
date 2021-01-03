#include "DataCenterClerk.h"
#include "DataCenter.h"

namespace SemperEngine
{
	namespace Core
	{

		void DataCenterClerk::Destroy()
		{
			if (dataCenter != nullptr)
			{
				dataCenter->Delete(id);
			}
		}

	}
}