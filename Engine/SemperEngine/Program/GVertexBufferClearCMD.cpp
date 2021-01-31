#include "GraphicCommand.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferClearCMD::GVertexBufferClearCMD(GraphicDataInfo info)
		{
			this->dataInfo = info;
		}

		GVertexBufferClearCMD::~GVertexBufferClearCMD()
		{
		}

		void GVertexBufferClearCMD::Excute()
		{
			auto data = GraphicResource::GetVertexData(dataInfo);
			GraphicResouceAPI::ClearVertexData(*data.get());
			GraphicResource::DeleteGraphicVertexData(dataInfo);
		}
	}
}