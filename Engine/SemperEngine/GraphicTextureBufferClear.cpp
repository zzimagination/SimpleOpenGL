#include "GraphicCommand.h"
#include "GraphicDataCenter.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		GTextureBufferClearCMD::GTextureBufferClearCMD(TextureCommandData data)
		{
			this->data = data;
		}

		GTextureBufferClearCMD::~GTextureBufferClearCMD()
		{
		}

		void GTextureBufferClearCMD::Excute()
		{
			GraphicResouceAPI::ClearTextureData(data->graphicData);
		}
	}
}
