#pragma once
#ifndef __RESOURCEOBJECTCENTER__
#define __RESOURCEOBJECTCENTER__

#include <memory>
#include <vector>
#include "TextureObject.h"
#include "MeshObject.h"
#include "ResourceObjectContainer.h"


namespace SemperEngine
{
	namespace Core
	{
		class ResourceObjectCenter
		{
		private:

			static TextureObjectContainer textures;

			static MeshObjectContainer cubes;

		public:

			static void DeleteObjects();

			static void NewObjects();

			static std::shared_ptr<TextureObject> CreateTexture();

			static std::shared_ptr<TextureObject> CreateTexture(TextureObject::Setting setting);

			static std::shared_ptr<TextureObject> LoadTexture(std::string file, bool share = false);

			static std::shared_ptr<TextureObject> LoadTexture(std::string file, bool share, TextureObject::Setting setting);

			static std::shared_ptr<TextureObject> CopyTexture(std::shared_ptr<TextureObject> texture);

			static void DeleteTexture(std::shared_ptr<TextureObject> tex);

			static std::shared_ptr<MeshObject> CreateCube();

			static std::shared_ptr<MeshObject> CreateCube(MeshObject::Setting setting);

			static std::shared_ptr<MeshObject> CopyMesh(std::shared_ptr<MeshObject> mesh);

			static void DeleteCube(std::shared_ptr<MeshObject> cube);

		};
	}
}

#endif // !__RESOURCEOBJECTCENTER__
