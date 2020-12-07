#include "ResourceLoader.h"
#include <TextureLib.h>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace TextureLib;

		TextureData* ResourceLoader::LoadTexture(std::string file)
		{
			auto texfile = TextureResource::Load(file);
			auto colorBuffer = new vector<unsigned char>();
			colorBuffer->resize(texfile.size);
			memcpy(colorBuffer->data(), texfile.textureData, texfile.size);
			texfile.Dispose();

			auto data = new TextureData();
			data->data.reset(colorBuffer);
			data->width = texfile.width;
			data->height = texfile.height;
			return data;
		}
	}
}