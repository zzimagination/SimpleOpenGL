#include "GraphicVertexBufferClear.h"
#include "GraphicRenderDraw.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GraphicVertexBufferClear::GraphicVertexBufferClear(shared_ptr<Vertex> data)
		{
			this->data = data;
			this->data->package.Dispose();
		}

		void GraphicVertexBufferClear::Excute()
		{
			GraphicRenderDraw::ClearVertexData(data->graphicData);
		}
	}
}
