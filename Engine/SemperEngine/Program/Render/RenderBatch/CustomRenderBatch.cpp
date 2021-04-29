#include "CustomRenderBatch.h"
#include <memory>

namespace Semper
{
	namespace Core
	{
		using namespace std;

		CustomRenderBatch::~CustomRenderBatch()
		{
		}

		void CustomRenderBatch::GenerateGraphicResource()
		{
			auto m = (MeshObject*)mesh->GetObject();
			m->CreateGraphicResource();
			auto mat = (MaterialObject*)material->GetObject();
			mat->CreateGraphicResource();
		}

		void CustomRenderBatch::RenderGraphicObject()
		{
			auto vertex = GetVertexInfo(mesh);
			auto operation = GetOperation(material);
			auto matrix = GetRenderMatrix(model, camera);
			auto shaderProperty = GetShaderProperty(material);
			GraphicRenderer::Render(vertex, operation, matrix, shaderProperty, this->_graphicRecords);
		}
	}
}