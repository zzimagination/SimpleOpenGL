#include "GraphicVertexBufferClear.h"
#include "GraphicRenderDraw.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferClearCMD::GVertexBufferClearCMD(shared_ptr<Vertex> data)
		{
			this->data = data;
			this->data->package.Dispose();
		}

		void GVertexBufferClearCMD::Excute()
		{
			auto gvd = data->graphicData;
			GraphicRenderDraw::ClearVertexData(gvd.VAO, gvd.VBO, gvd.EBO);
		}
	}
}
