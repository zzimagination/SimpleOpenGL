#include "GraphicVertexBuffer.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderDraw.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicVertexBuffer::GraphicVertexBuffer(RenderVertexData * gameData)
		{
			this->gameData = gameData;
		}

		void GraphicVertexBuffer::Excute()
		{
			auto graphicData = GraphicRenderDraw::AddVertexData(gameData);
			GraphicDataCenter::AddVertexData(graphicData);
		}
	}
}