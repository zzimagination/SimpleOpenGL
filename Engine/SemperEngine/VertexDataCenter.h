#pragma once
#ifndef __VERTEXDATA_CENTER__
#define __VERTEXDATA_CENTER__

#include <memory>
#include "FillList.h"
#include "ResourcePackage.h"
#include "DataCenter.h"
#include "VertexData.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class VertexDataCenter : public DataCenter
		{
		public:

			static FillList<GPResourceUnit<VertexData>> vertexDatas;

		public:

			static ResourcePackage<VertexData> InputData(VertexData* data);

			static void AddAndDelete();

		private:

			static std::vector<int> _addIndex;

			static std::vector<int> _removeIndex;

		private:

			static BaseData* GetData(int id);

			static void Destroy(int id);

			static GraphicDataInfo GetGDataInfo(int id);

			static void AddIndex(int id);

			static void RemoveIndex(int id);

		};
	}
}

#endif // !VERTEXDATA_CENTER
