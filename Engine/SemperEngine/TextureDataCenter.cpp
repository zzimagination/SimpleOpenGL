#include "TextureDataCenter.h"
#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"
#include <TextureLib.h>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;
		using namespace TextureLib;

		vector<ResourcePackage<TextureData>> TextureDataCenter::instances;

		std::vector<ResourceID> TextureDataCenter::unused;

		RsTextureRef TextureDataCenter::LoadTexture(std::string path)
		{
			auto tex = CreateTexture(path);
			ResourcePackage<TextureData> package(tex);
			package.onDestroy = Unload;
			ResourceID id = 0;
			if (unused.size() > 0)
			{
				id = *(unused.end() - 1);
				unused.pop_back();
				package.id = id;
				instances[id] = package;
			}
			else
			{
				id = (ResourceID)instances.size();
				package.id = id;
				instances.push_back(package);
			}
			GraphicDataCenter::AddTextureData(package);
			return RsTextureRef(new ResourceReference(package));
		}

		void TextureDataCenter::Unload(ResourceID id)
		{
			auto tex = instances[id];
			unused.push_back(id);
			GraphicDataCenter::RemoveTextureData(tex);
		}

		TextureData* TextureDataCenter::CreateTexture(std::string path)
		{
			auto file = TextureResource::Load(path);
			auto texture = new TextureData();
			texture->data = file.textureData;
			texture->width = file.width;
			texture->height = file.height;
			return texture;
		}

	}
}