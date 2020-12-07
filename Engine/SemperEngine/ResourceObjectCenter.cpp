#include "ResourceObjectCenter.h"
#include "ResourceDataCenter.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		TextureObjectContainer ResourceObjectCenter::textures;

		MeshObjectContainer ResourceObjectCenter::cubes;

		void ResourceObjectCenter::DeleteObjects()
		{
			textures.DeleteObjects();
			cubes.DeleteObjects();
		}

		void ResourceObjectCenter::NewObjects()
		{
			textures.NewObjects();
			cubes.NewObjects();
		}

		std::shared_ptr<TextureObject> ResourceObjectCenter::CreateTexture()
		{
			return textures.Create();
		}

		std::shared_ptr<TextureObject> ResourceObjectCenter::CreateTexture(TextureObject::Setting setting)
		{
			textures.Setting(setting);
			auto result = textures.Create();
			textures.ResetSetting();
			return result;
		}

		std::shared_ptr<TextureObject> ResourceObjectCenter::LoadTexture(std::string file, bool share)
		{
			if (share)
			{
				auto obj = textures.Find(file);
				if (obj != nullptr)
				{
					return obj;
				}
				return textures.LoadSave(file);
			}
			else
			{
				return textures.Load(file);
			}
		}

		std::shared_ptr<TextureObject> ResourceObjectCenter::LoadTexture(std::string file, bool share, TextureObject::Setting setting)
		{
			textures.Setting(setting);
			auto result = LoadTexture(file, share);
			textures.ResetSetting();
			return result;
		}

		std::shared_ptr<TextureObject> ResourceObjectCenter::CopyTexture(std::shared_ptr<TextureObject> texture)
		{
			return textures.Copy(texture);
		}

		void ResourceObjectCenter::DeleteTexture(std::shared_ptr<TextureObject> tex)
		{
			textures.Delete(tex);
		}

		std::shared_ptr<MeshObject> ResourceObjectCenter::CreateCube()
		{
			return cubes.CreateCube();
		}

		std::shared_ptr<MeshObject> ResourceObjectCenter::CreateCube(MeshObject::Setting setting)
		{
			cubes.Setting(setting);
			auto result = CreateCube();
			cubes.ResetSetting();
			return result;
		}

		std::shared_ptr<MeshObject> ResourceObjectCenter::CopyMesh(std::shared_ptr<MeshObject> mesh)
		{
			return cubes.Copy(mesh);
		}

		void ResourceObjectCenter::DeleteCube(std::shared_ptr<MeshObject> cube)
		{
			cubes.Delete(cube);
		}
	}
}