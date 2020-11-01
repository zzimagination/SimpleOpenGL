#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		int ScreenTextureData::vertexCount = 4;

		Float3 ScreenTextureData::vertices[4] = { Float3(-1,-1,0), Float3(1,-1,0), Float3(1,1,0), Float3(-1,1,0) };

		Float2 ScreenTextureData::uvs[4] = { Float2(0,1), Float2(1,1),Float2(1,0), Float2(0,0) };

		int ScreenTextureData::indices[6] = { 0,1,3,1,2,3 };
	}
}