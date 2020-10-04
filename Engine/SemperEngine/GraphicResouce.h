#pragma once
#ifndef GRAPHIC_RESOURCECALL
#define GRAPHIC_RESOURCECALL

#include "VertexData.h"
#include "GraphicVertexData.h"


namespace SemperEngine
{
	namespace Core
	{
		class GraphicResouce
		{
		public:

			static GraphicVertexData AddVertexData(VertexData* data);

			static void ClearVertexData(GraphicVertexData data);
		};
	}
}

#endif // !GRAPHIC_RESOURCECALL
