#include "Resource.h"
#include "ResourceObjectCenter.h"
#include "ResourceInternal.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	std::shared_ptr<Texture> Resource::WhiteTex()
	{
		return ResourceInternal::GetTexture(WHITE_TEXTURE);
	}

	std::shared_ptr<Texture> Resource::BlackTex()
	{
		return ResourceInternal::GetTexture(BLACK_TEXTURE);
	}

	std::shared_ptr<Texture> Resource::BumpTex()
	{
		return ResourceInternal::GetTexture(BUMP_TEXTURE);
	}

	shared_ptr<Texture> Resource::LoadTexture(string path, bool share)
	{
		auto tex = shared_ptr<Texture>(new Texture());
		ResourceObjectCenter::DeleteTexture(tex->object);
		auto fullPath = ExternalFile(path);
		tex->object = ResourceObjectCenter::LoadTexture(fullPath, share);
		return tex;
	}

	std::shared_ptr<Mesh> Resource::CreateCube()
	{
		auto mesh = shared_ptr<Mesh>(new Mesh);
		ResourceObjectCenter::DeleteCube(mesh->object);
		mesh->object = ResourceObjectCenter::CreateCube();
		return mesh;
	}

	std::string Resource::ExternalFile(std::string file)
	{
		auto result = string("Resources/");
		result.append(file);
		return result;
	}
}