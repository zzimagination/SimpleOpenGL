#include "ScreenRenderBatch.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		ScreenRenderBatch::ScreenRenderBatch()
		{
		}

		ScreenRenderBatch::~ScreenRenderBatch()
		{
		}

		void ScreenRenderBatch::GenerateGraphicResource()
		{
			((MaterialObject*)material->GetObject())->CreateGraphicResource();
		}

		void ScreenRenderBatch::RenderGraphicObject()
		{
			auto mesh = ResourceInternal::ScreenMesh();
			auto vertex = GetVertexInfo(mesh.get());
			auto operation = GetOperation(material);
			auto matrix = RenderMatrix();
			auto shaderPorperty = GetShaderProperty(material);
			GraphicRenderer::Render(vertex, operation, matrix, shaderPorperty, this->_graphicRecords);
		}
	}
}