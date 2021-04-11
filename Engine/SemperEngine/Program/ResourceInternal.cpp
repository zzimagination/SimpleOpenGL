#include "ResourceInternal.h"
#include "ResourceObjectCenter.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		constexpr const char* WHITE_TEXTURE = "white";
		constexpr const char* BLACK_TEXTURE = "black";
		constexpr const char* BUMP_TEXTURE = "bump";
		constexpr const char* SCREENVIEW_MATERIAL = "ScreenView";

#define PNG_EXTEND(name) string(name).append(".png") 

		shared_ptr<Mesh> ResourceInternal::_screenMesh;

		std::map<std::string, std::shared_ptr<Texture>> ResourceInternal::textureMap;
		std::map<std::string, std::shared_ptr<Material>> ResourceInternal::materialMap;

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

		std::shared_ptr<Material> ResourceInternal::ScreenViewMaterial()
		{
			return materialMap[SCREENVIEW_MATERIAL];
		}

		void ResourceInternal::PreLoad()
		{
			TextureObject::Setting setting;
			setting.readOnly = true;
			textureMap[WHITE_TEXTURE] = LoadTexture(PNG_EXTEND(WHITE_TEXTURE));
			textureMap[BLACK_TEXTURE] = LoadTexture(PNG_EXTEND(BLACK_TEXTURE));
			textureMap[BUMP_TEXTURE] = LoadTexture(PNG_EXTEND(BUMP_TEXTURE));

			_screenMesh = shared_ptr<Mesh>(new Mesh(MeshObject::CreateRectangle()));
			((MeshObject*)_screenMesh->GetObject())->CreateGraphicResource();

			auto screenViewMat = shared_ptr<Material>(new Material(SCREENVIEW_MATERIAL));
			materialMap.insert(pair<string, shared_ptr<Material>>(SCREENVIEW_MATERIAL, screenViewMat));
		}

		std::shared_ptr<Texture> ResourceInternal::GetTexture(std::string name)
		{
			auto target = textureMap.find(name);
			if (target != textureMap.end())
			{
				return target->second;
			}
			Debug::LogError({ "can't find texture", name });
			abort();
		}

		shared_ptr<Texture> ResourceInternal::LoadTexture(std::string name)
		{
			auto fullPath = InternalFile(name);
			auto obj = textureLibrary.Load(fullPath);
			auto texture = shared_ptr<Texture>(new Texture(obj));
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