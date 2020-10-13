#include "GraphicCommand.h"
#include "GraphicResouceAPI.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		GVertexBufferClearCMD::GVertexBufferClearCMD(shared_ptr<VertexCommandData> data)
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
