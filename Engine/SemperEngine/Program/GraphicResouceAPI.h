#pragma once
#ifndef __GRAPHIC_RESOURCECALL__
#define __GRAPHIC_RESOURCECALL__

#include "Common.h"
#include "Graphic.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicResouceAPI
		{
		public:

			static GraphicVertexData AddVertexData(GraphicVertexResource source);

			static void ClearVertexData(GraphicVertexData data);

			static GraphicTextureData AddTextureData(GraphicTextureResource source);

			static void ClearTextureData(GraphicTextureData data);
		};
	}
}

#endif // !GRAPHIC_RESOURCECALL
