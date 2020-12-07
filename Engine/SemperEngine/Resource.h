#pragma once
#ifndef __RESOURCE__
#define __RESOURCE__

#include <string>
#include <memory>
#include "Mesh.h"
#include "Texture.h"

namespace SemperEngine
{
	class Resource
	{
	public:

		static std::shared_ptr<Texture> WhiteTex();

		static std::shared_ptr<Texture> BlackTex();

		static std::shared_ptr<Texture> BumpTex();

		static std::shared_ptr<Texture> LoadTexture(std::string path, bool share = false);

		static std::shared_ptr<Mesh> CreateCube();

	private:

		static std::string ExternalFile(std::string file);
	};
}

#endif // !__RESOURCE__
