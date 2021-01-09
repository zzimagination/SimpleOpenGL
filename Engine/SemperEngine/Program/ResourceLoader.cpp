#include "ResourceLoader.h"
#include <TextureLib.h>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		TextureData* ResourceLoader::LoadTexture(std::string file)
		{
			auto texfile = TextureLib::LoadTexture(file);
			auto data = new TextureData();
			data->width = texfile->width;
			data->height = texfile->height;
			data->pixels.Resize(texfile->size);
			memcpy(data->pixels.DataPtr(), texfile->data.get(), texfile->size * sizeof(ColorByte));
			return data;
		}
	}
}