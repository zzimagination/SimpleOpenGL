#pragma once
#ifndef __GRAPHIC_RESOURCECALL__
#define __GRAPHIC_RESOURCECALL__

#include "VertexData.h"
#include "TextureData.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicResouceAPI
		{
		public:

			static GraphicVertexData AddVertexData(VertexData* data);

			static void ClearVertexData(GraphicVertexData data);

			static GraphicTextureData AddTextureData(TextureData* data);

			static void ClearTextureData(GraphicTextureData data);
		};
	}
}

#endif // !GRAPHIC_RESOURCECALL
