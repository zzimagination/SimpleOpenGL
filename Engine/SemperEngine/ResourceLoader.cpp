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
			auto data = new TextureData();
			data->data = texfile.textureData;
			data->width = texfile.width;
			data->height = texfile.height;
			return data;
		}

		std::string ResourceLoader::InternalFile(std::string file)
		{
			auto result = string("Internal/");
			result.append(file);
			return result;
		}
		std::string ResourceLoader::ExternalFile(std::string file)
		{
			auto result = string("Resources/");
			result.append(file);
			return result;
		}
	}
}