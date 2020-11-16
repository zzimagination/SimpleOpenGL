#include "ResourceManager.h"
#include "VertexDataCenter.h"
#include "TextureDataCenter.h"
#include "ResourceLoader.h"
#include "ResourceInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void ResourceManager::PreLoad()
		{
			PreLoadMesh();
			PreLoadTexture();
		}

		void ResourceManager::AddAndDelete()
		{
			VertexDataCenter::AddAndDelete();
			TextureDataCenter::AddAndDelete();
		}

		void ResourceManager::PreLoadTexture()
		{
			LoadInternalTexture(WHITE_TEXTURE);
			LoadInternalTexture(BLACK_TEXTURE);
			LoadInternalTexture(BUMP_TEXTURE);
		}
		void ResourceManager::LoadInternalTexture(std::string name)
		{
			auto fullPath = ResourceLoader::InternalFile(name);
			auto data = ResourceLoader::LoadTexture(fullPath);
			auto package = TextureDataCenter::InputData(data);
			auto texture = std::shared_ptr<Texture>(new Texture(package));
			ResourceInternal::AddTexture(name, texture);
		}
		void ResourceManager::PreLoadMesh()
		{
		}
	}
}