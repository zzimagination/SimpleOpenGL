#pragma once
#ifndef GRAPHIC_COMMANDDATA
#define GRAPHIC_COMMANDDATA

#include <memory>
#include "ResourcePackage.h"
#include "VertexData.h"
#include "GraphicVertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		template<class DATA, class GDATA>
		class GraphicCommandData
		{
		public:

			ResourcePackage<DATA> package;

			GDATA graphicData;

		public:

			GraphicCommandData() {}
			~GraphicCommandData() {}
		};

		typedef GraphicCommandData<VertexData, GraphicVertexData> Vertex;
	}
}

#endif // !GRAPHIC_COMMANDDATA
