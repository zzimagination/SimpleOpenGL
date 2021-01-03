#include "Resource.h"
#include "ResourceObjectCenter.h"
#include "ResourceInternal.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	ResourceTextureLibrary Resource::textureLibrary;

	shared_ptr<Texture> Resource::LoadTexture(string path)
	{
		auto fullPath = ExternalFile(path);
		auto object = textureLibrary.Load(fullPath);
		auto tex = shared_ptr<Texture>(new Texture(object));
		return tex;
	}

	std::shared_ptr<Mesh> Resource::CreateCube()
	{
		auto object = MeshObject::CreateCube();
		auto mesh = shared_ptr<Mesh>(new Mesh(object));
		return mesh;
	}

	void Resource::DisposeUnuse()
	{
		textureLibrary.DisposeUnuse();
	}

	std::string Resource::ExternalFile(std::string file)
	{
		auto result = string("Resources/");
		result.append(file);
		return result;
	}
}