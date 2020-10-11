#include "GraphicCommand.h"
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

		GVertexBufferCMD::~GVertexBufferCMD()
		{
		}

		void GVertexBufferCMD::Excute()
		{
			auto gvd = GraphicResouceAPI::AddVertexData(data->package.GetResource());
			this->data->graphicData = gvd;
			this->data->package.Dispose();
		}
	}
}