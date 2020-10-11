#include "GraphicTextureBufferClear.h"
#include "GraphicDataCenter.h"
#include "GraphicRenderAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		GraphicTextureBufferClear::GraphicTextureBufferClear(Texture * gameData)
		{
			this->gameData = gameData;
		}

		void GraphicTextureBufferClear::Excute()
		{
			auto graphicData = GraphicDataCenter::PopTextureData(gameData);
			GraphicRenderAPI::ClearTextureData(graphicData);
		}
	}
}
