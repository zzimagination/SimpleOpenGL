#include "TextureData.h"
#include <TextureLib.h>
#include "GraphicDataCenter.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace TextureLib;
		using namespace std;

		TextureData* TextureData::LoadFile(std::string png)
		{
			auto file = TextureResource::Load(png);
			auto texture = new TextureData();
			texture->data = file.textureData;
			texture->width = file.width;
			texture->height = file.height;
			return texture;
		}

		TextureData::TextureData()
		{
			width = 0;
			height = 0;
			isPackaged = false;
		}

		TextureData::~TextureData()
		{
			if (isPackaged)
			{
				GraphicDataCenter::RemoveTextureData(package);
			}
		}

		void TextureData::Package(ResourcePackage<TextureData> mine)
		{
			if (mine.GetResource() != this)
			{
				Debug::Log("not mine");
				throw "not mine";
			}
			this->package = mine;
			isPackaged = true;
			GraphicDataCenter::AddTextureData(package);
		}
	}
}