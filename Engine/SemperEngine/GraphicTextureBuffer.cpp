#include "GraphicTextureBuffer.h"
#include "GraphicRenderAPI.h"
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
			auto graphicData= GraphicRenderAPI::AddTextureData(gameData);
			GraphicDataCenter::AddTextureDate(graphicData);
		}
	}
}
