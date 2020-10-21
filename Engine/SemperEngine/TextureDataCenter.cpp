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

		shared_ptr<Texture> TextureDataCenter::LoadTexture(std::string path)
		{
			auto tex = TextureData::LoadFile(path);
			ResourcePackage<TextureData> package(tex);
			package.onDestroy = Unload;

			if (unused.size() > 0)
			{
				auto id = *(unused.end() - 1);
				unused.pop_back();
				package.id = id;
				instances[id] = package;
			}
			else
			{
				auto id = (ResourceID)instances.size();
				package.id = id;
				instances.push_back(package);
			}
			package.GetResource()->Package(package);
			return shared_ptr<Texture>(new Texture(package));
		}

		void TextureDataCenter::Unload(ResourceID id)
		{
			auto tex = instances[id];
			unused.push_back(id);
			GraphicDataCenter::RemoveTextureData(tex);
		}
	}
}