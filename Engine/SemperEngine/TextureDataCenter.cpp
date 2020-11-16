#include "TextureDataCenter.h"
#include "GraphicDataCenter.h"
#include "DataCenterClerk.h"
#include <TextureLib.h>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace TextureLib;

		FillList < TextureDataCenter::GPResourceUnit<TextureData> > TextureDataCenter::textures;

		vector<int> TextureDataCenter::_addIndex;

		vector<int> TextureDataCenter::_removeIndex;

		ResourcePackage<TextureData> TextureDataCenter::InputData(TextureData* data)
		{
			auto clerk = shared_ptr<DataCenterClerk>(new DataCenterClerk());
			clerk->getDataTo = GetData;
			clerk->addPathTo = AddPath;
			clerk->destoryTo = Destroy;
			clerk->getGDataInfo = GetGDataInfo;

			ResourcePackage<TextureData> package(data);
			package.clerk = clerk;

			GPResourceUnit<TextureData> unit;
			unit.package = package;

			clerk->id = textures.Add(unit);
			AddIndex(clerk->id);
			return package;
		}

		ResourcePackage<TextureData> TextureDataCenter::InputData(TextureData* data, string path)
		{
			auto package = InputData(data);
			package.clerk->AddPath(path);
			return package;
		}

		void TextureDataCenter::AddAndDelete()
		{
			for (int i = 0; i < _removeIndex.size(); i++)
			{
				auto info = textures[_removeIndex[i]].graphicDataInfo;
				GraphicDataCenter::RemoveTextureData(info);
				textures.Remove(_removeIndex[i]);
			}
			_removeIndex.clear();
			for (int i = 0; i < _addIndex.size(); i++)
			{
				auto package = textures[_addIndex[i]].package;
				auto info = GraphicDataCenter::AddTextureData(package.GetResource());
				textures[_addIndex[i]].graphicDataInfo = info;
			}
			_addIndex.clear();
		}

		BaseData* TextureDataCenter::GetData(int id)
		{
			return textures[id].package.GetResource();
		}

		void TextureDataCenter::AddPath(int id, std::string path)
		{
			textures[id].path = path;
		}

		void TextureDataCenter::Destroy(int id)
		{
			RemoveIndex(id);
		}
		GraphicDataInfo TextureDataCenter::GetGDataInfo(int id)
		{
			return textures[id].graphicDataInfo;
		}

		void TextureDataCenter::AddIndex(int id)
		{
			_addIndex.push_back(id);
		}

		void TextureDataCenter::RemoveIndex(int id)
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