#pragma once
#ifndef __RESOURCE__
#define __RESOURCE__

#include <string>
#include <memory>
#include "Mesh.h"
#include "Texture.h"
#include "ResourceTextureLibrary.h"

namespace SemperEngine
{
	class Resource
	{
	private:

		static Core::ResourceTextureLibrary textureLibrary;

	public:

		static std::shared_ptr<Texture> LoadTexture(std::string path);

		static std::shared_ptr<Mesh> CreateCube();

		static void DisposeUnuse();

	private:

		static std::string ExternalFile(std::string file);
	};
}

#endif // !__RESOURCE__
