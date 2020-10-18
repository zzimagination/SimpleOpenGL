#include "GraphicCommand.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferCMD::GVertexBufferCMD(VertexCommandData data)
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
			this->data->package.Dispose(this);
		}
	}
}