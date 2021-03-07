#pragma once
#ifndef __RESOURCEINTERNAL__
#define __RESOURCEINTERNAL__

#include <string>
#include <map>
#include <memory>
#include "Texture.h"
#include "Mesh.h"
#include "Material.h"
#include "ResourceTextureLibrary.h"
#include "ResourceConfig.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceInternal
		{
		private:

			static std::map<std::string, std::shared_ptr<Texture>> textureMap;

			static ResourceTextureLibrary textureLibrary;

			static std::shared_ptr<Mesh> _screenMesh;

			static std::map<std::string, std::shared_ptr<Material>> materialMap;

		public:

			static std::shared_ptr<Texture> WhiteTex();

			static std::shared_ptr<Texture> BlackTex();

			static std::shared_ptr<Texture> BumpTex();

			static std::shared_ptr<Mesh> ScreenMesh();
			
			static std::shared_ptr<Material> ScreenViewMat();

		public:

			static void PreLoad();

			static void Dispose();

			static std::shared_ptr<Texture> GetTexture(std::string name);



		private:

			static std::shared_ptr<Texture> LoadTexture(std::string name);

			static std::string InternalFile(std::string file);
		};
	}
}

#endif // !__RESOURCEINTERNAL__
