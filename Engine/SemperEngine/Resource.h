#pragma once
#ifndef __RESOURCE__
#define __RESOURCE__

#include "VertexDataCenter.h"
#include "TextureDataCenter.h"

namespace SemperEngine
{
	class Resource
	{
	public:

		static std::shared_ptr<Mesh> LoadCube(bool share=false);

		static std::shared_ptr<Texture> LoadTexture(std::string path, bool share = false);

	};
}

#endif // !__RESOURCE__
