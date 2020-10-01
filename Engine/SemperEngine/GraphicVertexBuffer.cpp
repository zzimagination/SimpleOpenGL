#include "GraphicVertexBuffer.h"
#include "GraphicRenderDraw.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GraphicVertexBuffer::GraphicVertexBuffer(shared_ptr<Vertex> data)
		{
			this->data = data;
			this->data->package.Use(this);
		}

		void GraphicVertexBuffer::Excute()
		{
			auto vd = data->package.GetResource();
			auto gvd = GraphicRenderDraw::AddVertexData(vd->vertices.data(), vd->uv.data(), vd->index.data(),vd->vertexCount);
			this->data->graphicData = gvd;
		}
	}
}