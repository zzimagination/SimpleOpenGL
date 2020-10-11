#pragma once
#ifndef __GRAPHIC_RESOURCECALL__
#define __GRAPHIC_RESOURCECALL__

#include "VertexData.h"
#include "GraphicVertexData.h"


namespace SemperEngine
{
	namespace Core
	{
		class GraphicResouceAPI
		{
		public:

			static GraphicVertexData AddVertexData(VertexData* data);

			static void ClearVertexData(GraphicVertexData data);
		};
	}
}

#endif // !GRAPHIC_RESOURCECALL
