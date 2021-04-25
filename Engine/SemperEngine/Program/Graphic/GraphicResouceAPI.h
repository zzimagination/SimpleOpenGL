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

			static GraphicVertexData AddVertexData(GraphicVertexData* data);

			static void ClearVertexData(GraphicVertexData* data);

			static GraphicTextureData AddTextureData(GraphicTextureData* data);

			static void ClearTextureData(GraphicTextureData* data);
		};
	}
}

#endif // !GRAPHIC_RESOURCECALL
