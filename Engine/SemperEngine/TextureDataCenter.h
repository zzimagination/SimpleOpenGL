#pragma once
#ifndef __TEXTURE_DATACENTER__
#define __TEXTURE_DATACENTER__

#include <string>
#include <memory>
#include <vector>
#include <map>
#include "FillList.h"
#include "DataCenter.h"
#include "Texture.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class TextureDataCenter : public DataCenter
		{
		public:

			static FillList < GPResourceUnit<TextureData> > textures;

		public:

			static ResourcePackage<TextureData> InputData(TextureData* data);

			static ResourcePackage<TextureData> InputData(TextureData* data, std::string path);

			static void AddAndDelete();

		private:

			static std::vector<int> _addIndex;

			static std::vector<int> _removeIndex;

		private:

			static BaseData* GetData(int id);

			static void AddPath(int id, std::string path);

			static void Destroy(int id);

			static GraphicDataInfo GetGDataInfo(int id);

			static void AddIndex(int id);

			static void RemoveIndex(int id);
		};
	}
}

#endif // !__TEXTURE_DATACENTER__
