#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		int ScreenTextureData::vertexCount = 4;

		Vector3 ScreenTextureData::vertices[4] = { Vector3(-1,-1,0), Vector3(1,-1,0), Vector3(1,1,0), Vector3(-1,1,0) };

		Vector2 ScreenTextureData::uvs[4] = { Vector2(0,1), Vector2(1,1),Vector2(1,0), Vector2(0,0) };

		int ScreenTextureData::indices[6] = { 0,1,3,1,2,3 };
	}
}