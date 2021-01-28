#pragma once
#ifndef __RESOURCE__
#define __RESOURCE__

#include <string>
#include <memory>
#include "Texture.h"
#include "Model.h"
#include "ResourceTextureLibrary.h"
#include "ResourceModelLibrary.h"

namespace SemperEngine
{
	class Resource
	{
	private:

		static Core::ResourceTextureLibrary textureLibrary;

		static Core::ResourceModelLibrary modelLibrary;

	public:

		static std::shared_ptr<Texture> LoadTexture(std::string path);

		static std::shared_ptr<Mesh> CreateCube();

		static std::shared_ptr<Model> LoadModel(std::string path);

		static void DisposeUnuse();

	private:

		static std::string ExternalFile(std::string file);
	};
}

#endif // !__RESOURCE__
