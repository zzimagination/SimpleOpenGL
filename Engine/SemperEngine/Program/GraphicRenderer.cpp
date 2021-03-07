#include "GraphicRenderer.h"
#include "GraphicCommandManager.h"
#include "GraphicResource.h"
#include "Graphic/GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		bool GraphicRenderer::useRecord = false;

		void GraphicRenderer::Wireframe(bool enable)
		{
			auto cmd = shared_ptr<GWireframeCMD>(new GWireframeCMD(enable));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(
			GraphicVertexInfo vertex,
			RenderOperation operation,
			RenderMatrix matrix,
			ShaderProperty sproperty,
			vector<GraphicTextureInfo> textures)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertex = vertex;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->shaderProperty.Add(MODEL_MATRIX, matrix.model);
			cmd->shaderProperty.Add(VIEW_MATRIX, matrix.view);
			cmd->shaderProperty.Add(PROJECTION_MARIX, matrix.projection);
			cmd->textures = textures;
			cmd->useRecord = useRecord;
			useRecord = false;
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(GraphicVertexInfo vertex, RenderOperation operation, ShaderProperty sproperty, std::vector<GraphicTextureInfo> textures)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertex = vertex;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->textures = textures;
			cmd->useRecord = useRecord;
			useRecord = false;
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(GraphicVertexInfo vertex, ShaderProperty sproperty, std::vector<GraphicTextureInfo> textures)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertex = vertex;
			RenderOperation operation;
			operation.depth = false;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->textures = textures;
			cmd->useRecord = useRecord;
			useRecord = false;
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Clear(Color color, Graphic::ClearMode mode)
		{
			auto cmd = shared_ptr<GClearCMD>(new GClearCMD(color, mode));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Clear(Color color)
		{
			auto cmd = shared_ptr<GClearCMD>(new GClearCMD(color, ClearColorDepth));
			GraphicCommandManager::AddRender(cmd);
		}
		void GraphicRenderer::CreateRecord(std::string name)
		{
			auto cmd = shared_ptr<GCMD_CreateRecord>(new GCMD_CreateRecord);
			cmd->name = name;
			GraphicCommandManager::AddRender(cmd);
		}
		void GraphicRenderer::StopRecord()
		{
			auto cmd = shared_ptr<GCMD_StopRecord>(new GCMD_StopRecord);
			GraphicCommandManager::AddRender(cmd);
		}
		void GraphicRenderer::UseRecord()
		{
			useRecord = true;
		}
		void GraphicRenderer::RenderRecord(GraphicVertexInfo vertex, RenderOperation operation ,ShaderProperty sproperty)
		{
			auto cmd = shared_ptr<GCMD_DrawRecord>(new GCMD_DrawRecord());
			cmd->vertex = vertex;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			GraphicCommandManager::AddRender(cmd);
		}
	}
}