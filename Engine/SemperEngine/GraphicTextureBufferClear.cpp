#include "GraphicCommand.h"
#include "GraphicDataCenter.h"
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
			auto data = GraphicDataCenter::GetTextureData(dataInfo);
			GraphicResouceAPI::ClearTextureData(*data.get());
			GraphicDataCenter::DeleteGraphicTextureData(dataInfo);
		}
	}
}
