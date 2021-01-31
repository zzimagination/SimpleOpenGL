#include "GraphicCommand.h"
#include "GraphicResource.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GTextureBufferClearCMD::GTextureBufferClearCMD(GraphicDataInfo info)
		{
			this->dataInfo = info;
		}

		GTextureBufferClearCMD::~GTextureBufferClearCMD()
		{
		}

		void GTextureBufferClearCMD::Excute()
		{
			auto data = GraphicResource::GetTextureData(dataInfo);
			GraphicResouceAPI::ClearTextureData(*data.get());
			GraphicResource::DeleteGraphicTextureData(dataInfo);
		}
	}
}
