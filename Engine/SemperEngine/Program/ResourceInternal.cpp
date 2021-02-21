#include "ResourceInternal.h"
#include "ResourceObjectCenter.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

#define PNG_EXTEND(name) string(name).append(".png") 

		shared_ptr<Mesh> ResourceInternal::_screenMesh;

		std::map<std::string, std::shared_ptr<Texture>> ResourceInternal::textureMap;

		ResourceTextureLibrary ResourceInternal::textureLibrary;

		std::shared_ptr<Texture> ResourceInternal::WhiteTex()
		{
			return GetTexture(WHITE_TEXTURE);
		}

		std::shared_ptr<Texture> ResourceInternal::BlackTex()
		{
			return GetTexture(BLACK_TEXTURE);
		}

		std::shared_ptr<Texture> ResourceInternal::BumpTex()
		{
			return GetTexture(BUMP_TEXTURE);
		}

		std::shared_ptr<Mesh> ResourceInternal::ScreenMesh()
		{
			return _screenMesh;
		}

		void ResourceInternal::PreLoad()
		{
			TextureObject::Setting setting;
			setting.readOnly = true;
			textureMap[WHITE_TEXTURE] = LoadTexture(PNG_EXTEND(WHITE_TEXTURE));
			textureMap[BLACK_TEXTURE] = LoadTexture(PNG_EXTEND(BLACK_TEXTURE));
			textureMap[BUMP_TEXTURE] = LoadTexture(PNG_EXTEND(BUMP_TEXTURE));

			_screenMesh = shared_ptr<Mesh>(new Mesh(MeshObject::CreateRectangle()));
			_screenMesh->GetObject()->CreateGraphicResource();
		}

		std::shared_ptr<Texture> ResourceInternal::GetTexture(std::string name)
		{
			auto target = textureMap.find(name);
			if (target != textureMap.end())
			{
				return target->second;
			}
			string log = "can't find texture";
			log.append(name);
			Debug::Log(log);
			throw log;
		}

		shared_ptr<Texture> ResourceInternal::LoadTexture(std::string name)
		{
			auto fullPath = InternalFile(name);
			auto obj = textureLibrary.Load(fullPath);
			auto texture = shared_ptr<Texture>(new Texture(obj));
			texture->GetObject()->CreateGraphicResource();
			return texture;
		}
		 
		void ResourceInternal::Dispose()
		{
			_screenMesh.reset();
			textureMap.clear();
			textureLibrary.DisposeUnuse();
		}

		std::string ResourceInternal::InternalFile(std::string file)
		{
			auto result = string("Internal/");
			result.append(file);
			return result;
		}
	}
}