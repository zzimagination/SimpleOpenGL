#include "GraphicCommand.h"
#include "GraphicResouce.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferClearCMD::GVertexBufferClearCMD(shared_ptr<Vertex> data)
		{
			this->data = data;
		}

		GVertexBufferClearCMD::~GVertexBufferClearCMD()
		{
		}

		void GVertexBufferClearCMD::Excute()
		{
			GraphicResouceAPI::ClearVertexData(data->graphicData);
		}
	}
}
