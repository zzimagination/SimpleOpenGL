#include "GraphicCommand.h"
#include "GraphicResouceAPI.h"
#include "GraphicResource.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GTextureBufferCMD::GTextureBufferCMD(GraphicDataInfo info)
		{
			this->dataInfo = info;
		}

		GTextureBufferCMD::~GTextureBufferCMD()
		{
		}

		void GTextureBufferCMD::Excute()
		{
			auto data = GraphicResource::GetTextureData(dataInfo);
			auto tmp = GraphicResouceAPI::AddTextureData(data->GetSource());
			data->glid = tmp.glid;
			data->Complete();
		}
	}
}