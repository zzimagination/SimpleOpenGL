#pragma once
#ifndef __SCREEN_TEXTUREDATA__
#define __SCREEN_TEXTUREDATA__

#include "Mathz.h"

namespace SemperEngine
{
	namespace Core
	{
		struct ScreenTextureData
		{
			static int vertexCount;

			static Float3 vertices[4];

			static Float2 uvs[4];

			static int indices[6];
		};
	}
}

#endif // !__SCREENTEXTURE__
