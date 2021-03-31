#include "GCMD_VertexBuffer.h"
#include "../GraphicResource.h"

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
			auto data = GraphicResource::GetVertexData(dataInfo);
			auto tmp = GraphicResouceAPI::AddVertexData(data->source);
			data->VAO = tmp.VAO;
			data->VBO = tmp.VBO;
			data->EBO = tmp.EBO;
			data->indexDraw = tmp.indexDraw;
			data->pointCount = tmp.pointCount;
			data->Complete();
		}
	}
}