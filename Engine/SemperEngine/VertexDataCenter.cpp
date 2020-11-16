#include "VertexDataCenter.h"
#include "GraphicDataCenter.h"
#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		FillList<VertexDataCenter::GPResourceUnit<VertexData>> VertexDataCenter::vertexDatas;

		vector<int> VertexDataCenter::_addIndex;

		vector<int> VertexDataCenter::_removeIndex;

		ResourcePackage<VertexData> VertexDataCenter::InputData(VertexData* data)
		{
			auto clerk = shared_ptr<DataCenterClerk>(new DataCenterClerk());
			clerk->getDataTo = GetData;
			clerk->destoryTo = Destroy;
			clerk->getGDataInfo = GetGDataInfo;

			ResourcePackage<VertexData> package(data);
			package.clerk = clerk;

			GPResourceUnit<VertexData> unit;
			unit.package = package;

			clerk->id = vertexDatas.Add(unit);
			AddIndex(clerk->id);
			return package;
		}

		void VertexDataCenter::AddAndDelete()
		{
			for (int i = 0; i < _removeIndex.size(); i++)
			{
				auto info = vertexDatas[_removeIndex[i]].graphicDataInfo;
				GraphicDataCenter::RemoveVertexData(info);
				vertexDatas.Remove(_removeIndex[i]);
			}
			_removeIndex.clear();
			for (int i = 0; i < _addIndex.size(); i++)
			{
				auto package = vertexDatas[_addIndex[i]].package;
				auto info = GraphicDataCenter::AddVertexData(package.GetResource());
				vertexDatas[_addIndex[i]].graphicDataInfo = info;
			}
			_addIndex.clear();
		}

		BaseData* VertexDataCenter::GetData(int id)
		{
			return vertexDatas[id].package.GetResource();
		}

		void VertexDataCenter::Destroy(int id)
		{
			RemoveIndex(id);
		}

		GraphicDataInfo VertexDataCenter::GetGDataInfo(int id)
		{
			return vertexDatas[id].graphicDataInfo;
		}

		void VertexDataCenter::AddIndex(int id)
		{
			_addIndex.push_back(id);
		}

		void VertexDataCenter::RemoveIndex(int id)
		{
			for (int i = 0; i < _addIndex.size(); i++)
			{
				if (_addIndex[i] == id)
				{
					_addIndex.erase(_addIndex.begin() + i);
					return;
				}
			}
			_removeIndex.push_back(id);
		}
	}
}