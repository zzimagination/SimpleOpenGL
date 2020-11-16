#pragma once
#ifndef __DATACENTER_CLERK__
#define __DATACENTER_CLERK__

#include <string>
#include <memory>
#include "BaseData.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class DataCenterClerk
		{
		public:

			int id;

			typedef void (*ADDPATH)(int, std::string);

			ADDPATH addPathTo;

			typedef void (*DESTORY)(int);

			DESTORY destoryTo;

			typedef BaseData* (*GETDATA)(int);
			
			GETDATA getDataTo;

			typedef GraphicDataInfo (*GETGDATAINFO)(int);

			GETGDATAINFO getGDataInfo;

		public:

			void AddPath(std::string path);

			void Destory();

			BaseData* GetData();

			GraphicDataInfo GetGDataInfo();
		};
	}
}

#endif // !__DATACENTER_CLERK__
