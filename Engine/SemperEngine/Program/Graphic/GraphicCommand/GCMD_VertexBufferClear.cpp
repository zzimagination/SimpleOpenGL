#include "GCMD_VertexBufferClear.h"
#include "../GraphicResource.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		GCMD_DeleteVertex::GCMD_DeleteVertex(GraphicVertexData* data, DeleteFunc func)
		{
			this->vertexData = data;
			this->deleteFunc = func;
		}

		GCMD_DeleteVertex::~GCMD_DeleteVertex()
		{
		}

		void GCMD_DeleteVertex::Excute()
		{
			GraphicResouceAPI::ClearVertexData(vertexData);
			if (deleteFunc == nullptr)
			{
				delete vertexData;
			}
			else
			{
				deleteFunc(vertexData);
			}
		}
	}
}