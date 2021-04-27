#include "GCMD_CreateVertex.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		GCMD_CreateVertex::GCMD_CreateVertex(GraphicVertexData* data)
		{
			this->vertexData = data;
		}

		GCMD_CreateVertex::~GCMD_CreateVertex()
		{
		}

		void GCMD_CreateVertex::Execute()
		{
			auto tmp = GraphicResouceAPI::AddVertexData(vertexData);
			if (tmp.EBO == 0)
			{
				this->vertexData->SetGL(tmp.VAO, tmp.VBO, tmp.pointCount);
			}
			else
			{
				this->vertexData->SetGL(tmp.VAO, tmp.VBO, tmp.EBO, tmp.pointCount);
			}
		}
	}
}