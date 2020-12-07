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
				dataCenter->Destroy(id);
			}
		}

		void DataCenterClerk::AddPath(std::string path)
		{
			if (dataCenter != nullptr)
			{
				dataCenter->AddPath(id, path);
			}
		}

	}
}