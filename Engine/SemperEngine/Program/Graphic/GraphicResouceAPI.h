#ifndef __GRAPHIC_RESOURCECALL__
#define __GRAPHIC_RESOURCECALL__

#include "Graphic.h"
#include "GraphicData.h"

namespace Semper
{
	namespace Core
	{
		class GraphicResouceAPI
		{
		public:

#pragma region Vertex

			static GraphicVertexData AddVertexData(GraphicVertexData* data);

			static void ClearVertexData(GraphicVertexData* data);

#pragma endregion

#pragma region Texture

			static GraphicTextureData AddTextureData(GraphicTextureData* data);

			static void ClearTextureData(GraphicTextureData* data);

#pragma endregion
		};
	}
}

#endif // !GRAPHIC_RESOURCECALL
