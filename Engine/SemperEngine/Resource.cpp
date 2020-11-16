#include "Resource.h"
#include "VertexDataCenter.h"
#include "TextureDataCenter.h"
#include "GraphicDataCenter.h"
#include "ResourceLoader.h"
#include "ResourceInternal.h"
#include "ResourceManager.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	shared_ptr<Mesh> Resource::LoadCube(bool share)
	{
		return ResourceInternal::GetCube();
	}

	std::weak_ptr<Texture> Resource::WhiteTex()
	{
		return ResourceInternal::GetTexture(WHITE_TEXTURE);
	}

	std::weak_ptr<Texture> Resource::BlackTex()
	{
		return ResourceInternal::GetTexture(BLACK_TEXTURE);
	}

	std::weak_ptr<Texture> Resource::BumpTex()
	{
		return ResourceInternal::GetTexture(BUMP_TEXTURE);
	}

	shared_ptr<Texture> Resource::LoadTexture(string path, bool share)
	{
		auto fullPath = ResourceLoader::ExternalFile(path);
		auto data = ResourceLoader::LoadTexture(fullPath);
		auto package = TextureDataCenter::InputData(data, path);
		auto texture = shared_ptr<Texture>(new Texture(package));
		return texture;
	}
}