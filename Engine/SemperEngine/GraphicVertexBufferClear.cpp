#include "GraphicVertexBufferClear.h"
#include "GraphicResouce.h"

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
			GraphicResouce::ClearVertexData(data->graphicData);
		}
	}
}
