#include "RenderBatch.h"
#include "Debug.h"
#include "Graphic/GraphicRenderer.h"
#include "ResourceInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;


		GraphicVertexInfo RenderBatch::GetVertexInfo(Mesh* mesh)
		{
			GraphicVertexInfo info;
			info.name = mesh->GetObject()->name;
			info.info = mesh->GetObject()->graphicDataInfo;
			return info;
		}

		RenderMatrix RenderBatch::GetRenderMatrix(Matrix4x4 model, CameraObject* camera)
		{
			RenderMatrix matrix;
			matrix.model = model;
			matrix.projection = camera->projectMatrix;
			matrix.view = camera->viewMatrix;
			return matrix;
		}

		RenderOperation RenderBatch::GetOperation(Material* material)
		{
			return material->GetObject()->renderOperation;
		}

		ShaderProperty RenderBatch::GetShaderProperty(Material* material)
		{
			return material->GetObject()->shaderProperty;
		}

		std::vector<GraphicTextureInfo> RenderBatch::GetTextures(Material* material)
		{
			vector<GraphicTextureInfo> infos;
			auto source = material->GetTextures();
			for (size_t i = 0; i < source.size(); i++)
			{
				GraphicTextureInfo info;
				info.index = (int)i;
				info.info = source[i]->GetObject()->graphicDataInfo;
				info.name = source[i]->GetObject()->name;
				infos.push_back(info);
			}
			return infos;
		}

		RenderBatch::~RenderBatch()
		{
		}

		ClearBatch::ClearBatch()
		{
			clearColor = Color(Float3(1, 1, 1));
			clearMode = ClearColorDepth;
		}

		ClearBatch::ClearBatch(Color color, Graphic::ClearMode mode) : clearColor(color), clearMode(mode)
		{
		}

		ClearBatch::~ClearBatch()
		{
		}

		void ClearBatch::RenderGraphicObject()
		{
			GraphicRenderer::Clear(clearColor, clearMode);
		}

		void ClearBatch::GenerateGraphicResource()
		{
		}

		CustomRenderBatch::~CustomRenderBatch()
		{
		}
		void CustomRenderBatch::RenderGraphicObject()
		{
			auto v = GetVertexInfo(mesh);
			auto operation = GetOperation(material);
			auto matrix = GetRenderMatrix(model, camera);
			auto shaderProperty = GetShaderProperty(material);
			auto textures = GetTextures(material);
			GraphicRenderer::Render(v, operation, matrix, shaderProperty, textures, useRecord, recordIDs);
		}
		void CustomRenderBatch::GenerateGraphicResource()
		{
			mesh->GetObject()->CreateGraphicResource();
			material->GetObject()->CreateGraphicResource();
		}
		void ScreenRenderBatch::GenerateGraphicResource()
		{
			material->GetObject()->CreateGraphicResource();
		}
		void ScreenRenderBatch::RenderGraphicObject()
		{
			RenderMatrix matrix;
			auto v = GetVertexInfo(ResourceInternal::ScreenMesh().get());
			auto operation = GetOperation(material);
			auto shaderPorperty = GetShaderProperty(material);
			auto textures = GetTextures(material);
			GraphicRenderer::Render(v, operation, shaderPorperty, textures, useRecord, recordIDs);
		}
	}
}
