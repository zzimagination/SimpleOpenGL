#ifndef RENDERVERTEX
#define RENDERVERTEX
#include "Mathz.h"

namespace SemperEngine {
	class RenderVertex {
	public:

		virtual int VertexCount() = 0;

		virtual Vector3* GetVertices() = 0;

		virtual Vector2* GetUV() = 0;

		virtual int* GetIndices() = 0;
	};
}
#endif // !RENDERVERTEX
