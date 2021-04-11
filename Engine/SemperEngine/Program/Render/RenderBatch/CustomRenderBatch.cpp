#include "CustomRenderBatch.h"

namespace SemperEngine
{
	namespace Core
	{
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
			auto textures = GetTextures(material);
			auto records = RenderRecordManager::GetGraphicRecords(this->records);
			GraphicRenderer::Render(vertex, operation, matrix, shaderProperty, textures, records);
		}
	}
}