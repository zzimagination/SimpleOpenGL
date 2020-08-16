#ifndef GRAPHIC_RENDER
#define GRAPHIC_RENDER

#include <vector>
#include "VertexData.h"
#include "TextureData.h"
namespace SemperEngine {
	using namespace std;

	class RenderVertex;
	class Texture;

	class GraphicRender
	{
	public:

		static void Render();

		static VertexData * GetVertexData(RenderVertex * v);

		static vector<TextureData*> GetTextureData(vector<Texture*> tex);
	};
}
#endif // !GraphicRender
