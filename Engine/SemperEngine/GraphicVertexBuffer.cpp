#include "GraphicVertexBuffer.h"
#include "GraphicResouce.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferCMD::GVertexBufferCMD(shared_ptr<Vertex> data)
		{
			this->data = data;
			this->data->package.Use(this);
		}

		void GVertexBufferCMD::Excute()
		{
			auto gvd = GraphicResouce::AddVertexData(data->package.GetResource());
			this->data->graphicData = gvd;
		}
	}
}