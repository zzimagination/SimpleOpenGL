#include "GraphicCommand.h"
#include "GraphicResouceAPI.h"
#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GTextureBufferCMD::GTextureBufferCMD(TextureCommandData data)
		{
			this->data = data;
			this->data->package.Use(this);
		}

		GTextureBufferCMD::~GTextureBufferCMD()
		{
		}

		void GTextureBufferCMD::Excute()
		{
			auto gdata = GraphicResouceAPI::AddTextureData(data->package.GetResource());
			data->graphicData = gdata;
			data->package.Dispose(this);
		}
	}
}
