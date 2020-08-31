#ifndef GRAPHIC_RENDER
#define GRAPHIC_RENDER

#include <vector>
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
namespace SemperEngine {
	using namespace std;

	class RenderVertexData;
	class Texture;

	class GraphicRender
	{
	public:

		static void Render();

		static GraphicVertexData * GetVertexData(RenderVertexData * v);

		static vector<GraphicTextureData*> GetTextureData(vector<Texture*> tex);
	};
}
#endif // !GraphicRender
