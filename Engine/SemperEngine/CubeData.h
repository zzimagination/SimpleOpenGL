#ifndef __CUBEDATA__
#define __CUBEDATA__

#include <vector>
#include "Mathz.h"

namespace SemperEngine {

	class CubeData
	{
	public:

		static int vertexCount;

		static Vector3 vertices[24];

		static Vector2 uvs[24];

		static int indices[36];
	};

}
#endif // !CUBE

