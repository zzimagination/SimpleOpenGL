#include "GraphicCommand.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferCMD::GVertexBufferCMD(GraphicDataInfo info)
		{
			this->dataInfo = info;
		}

		GVertexBufferCMD::~GVertexBufferCMD()
		{
		}

		void GVertexBufferCMD::Excute()
		{
			auto data = GraphicDataCenter::GetVertexData(dataInfo);
			auto tmp = GraphicResouceAPI::AddVertexData(data->GetSource());
			data->VAO = tmp.VAO;
			data->VBO = tmp.EBO;
			data->EBO = tmp.EBO;
			data->pointCount = tmp.pointCount;
			data->Complete();
		}
	}
}