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
			GraphicRenderer::Clear(Color::Black(), ClearColorDepth);
			auto mesh = ResourceInternal::ScreenMesh();
			auto vertex = GetVertexInfo(mesh.get());
			auto operation = GetOperation(material);
			auto shaderPorperty = GetShaderProperty(material);
			auto textures = GetTextures(material);
			vector<int> records = {};
			GraphicRenderer::Render(vertex, operation, shaderPorperty, textures, records);
		}
	}
}