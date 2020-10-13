#include "TextureDataCenter.h"
#include <TextureLib.h>
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace TextureLib;

		std::vector<ResourcePackage<Texture>> TextureDataCenter::instances;


		ResourcePackage<Texture> TextureDataCenter::LoadTexture(std::string path)
		{
			auto tex = CreateTexture(path);
			ResourcePackage<Texture> package(tex);
			instances.push_back(package);
			GraphicDataCenter::AddTextureData(package);
			return package;
		}

		void TextureDataCenter::UnloadUnuse()
		{
			vector<ResourcePackage<Texture>> newVector;
			for (int i = 0; i < instances.size(); i++)
			{
				if (UnloadOnce(instances[i]))
				{
					continue;
				}
				newVector.push_back(instances[i]);
			}
			instances = newVector;
		}

		Texture* TextureDataCenter::CreateTexture(std::string path)
		{
			auto file = TextureResource::Load(path);
			auto tex = new Texture();
			tex->data = file.textureData;
			tex->width = file.width;
			tex->height = file.height;
			return tex;
		}

		bool TextureDataCenter::UnloadOnce(ResourcePackage<Texture> package)
		{
			if (*package._useCount > 0)
			{
				return false;
			}
			GraphicDataCenter::RemoveTextureData(package);
			package.Destory();
			return true;
		}

	}
}