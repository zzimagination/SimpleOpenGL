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

		static std::shared_ptr<Mesh> LoadCube(bool share=false);

		static std::weak_ptr<Texture> WhiteTex();

		static std::weak_ptr<Texture> BlackTex();

		static std::weak_ptr<Texture> BumpTex();

		static std::shared_ptr<Texture> LoadTexture(std::string path, bool share = false);

	};
}

#endif // !__RESOURCE__
