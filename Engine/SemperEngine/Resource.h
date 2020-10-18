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

		static Core::RsVertexRef LoadCube(bool share=false);

		static Core::RsTextureRef LoadTexture(std::string path, bool share = false);
	};
}

#endif // !__RESOURCE__
