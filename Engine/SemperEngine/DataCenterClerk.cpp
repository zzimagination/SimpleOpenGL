#include "DataCenterClerk.h"

namespace SemperEngine
{
	namespace Core
	{
		void DataCenterClerk::AddPath(std::string path)
		{
			if (addPathTo != nullptr)
			{
				addPathTo(id, path);
			}
		}
		void DataCenterClerk::Destory()
		{
			if (destoryTo != nullptr)
			{
				destoryTo(id);
			}
		}
		BaseData* DataCenterClerk::GetData()
		{
			if (getDataTo != nullptr)
			{
				return getDataTo(id);
			}
			return nullptr;
		}
		GraphicDataInfo DataCenterClerk::GetGDataInfo()
		{
			if (getGDataInfo != nullptr)
			{
				return getGDataInfo(id);
			}
			return GraphicDataInfo();
		}
	}
}