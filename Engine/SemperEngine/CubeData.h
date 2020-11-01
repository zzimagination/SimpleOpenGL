#ifndef __CUBEDATA__
#define __CUBEDATA__

#include <vector>
#include "Mathz.h"

namespace SemperEngine {

	struct CubeData
	{
		static int vertexCount;

		static Float3 vertices[24];

		static Float2 uvs[24];

		static int indices[36];
	};

}
#endif // !CUBE

