#include "GraphicVertexBufferClear.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderDraw.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicVertexBufferClear::GraphicVertexBufferClear(RenderVertexData * gameData)
		{
			this->gameData = gameData;
		}

		void GraphicVertexBufferClear::Excute()
		{
			auto graphicData = GraphicDataCenter::PopVertexData(gameData);
			GraphicRenderDraw::ClearVertexData(graphicData);
		}
	}
}
