#include "GraphicTextureBuffer.h"
#include "GraphicRenderDraw.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicTextureBuffer::GraphicTextureBuffer(Texture * gameData)
		{
			this->gameData = gameData;
		}

		void GraphicTextureBuffer::Excute()
		{
			auto graphicData= GraphicRenderDraw::AddTextureData(gameData);
			GraphicDataCenter::AddTextureDate(graphicData);
		}
	}
}
