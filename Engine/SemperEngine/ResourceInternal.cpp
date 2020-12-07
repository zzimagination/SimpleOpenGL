#include "ResourceInternal.h"
#include "ResourceObjectCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

#define TEXPATH(name) string(name).append(".png") 

		std::map<std::string, std::shared_ptr<Texture>> ResourceInternal::textures;

		void ResourceInternal::PreLoad()
		{
			TextureObject::Setting setting;
			setting.readOnly = true;
			textures[WHITE_TEXTURE] = LoadTexture(TEXPATH(WHITE_TEXTURE), setting);
			textures[BLACK_TEXTURE] = LoadTexture(TEXPATH(BLACK_TEXTURE), setting);
			textures[BUMP_TEXTURE] = LoadTexture(TEXPATH(BUMP_TEXTURE), setting);
		}

		std::shared_ptr<Texture> ResourceInternal::GetTexture(std::string name)
		{
			auto target = textures.find(name);
			if (target != textures.end())
			{
				return shared_ptr<Texture>(target->second->Copy());
			}
			return std::shared_ptr<Texture>();
		}

		std::shared_ptr<Texture> ResourceInternal::LoadTexture(std::string name)
		{
			return LoadTexture(name, TextureObject::Setting());
		}

		shared_ptr<Texture> ResourceInternal::LoadTexture(std::string name, TextureObject::Setting setting)
		{
			auto fullPath = InternalFile(name);
			auto obj = ResourceObjectCenter::LoadTexture(fullPath, true, setting);
			auto texture = shared_ptr<Texture>(new Texture());
			ResourceObjectCenter::DeleteTexture(texture->object);
			texture->object = obj;
			return texture;
		}

		std::shared_ptr<Mesh> ResourceInternal::CreateCube()
		{
			auto obj = ResourceObjectCenter::CreateCube();
			auto cube = shared_ptr<Mesh>(new Mesh);
			ResourceObjectCenter::DeleteCube(cube->object);
			cube->object = obj;
			return cube;
		}

		void ResourceInternal::Dispose()
		{
			textures.clear();
		}

		std::string ResourceInternal::InternalFile(std::string file)
		{
			auto result = string("Internal/");
			result.append(file);
			return result;
		}
	}
}