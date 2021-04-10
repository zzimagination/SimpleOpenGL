#include "GraphicRenderer.h"
#include "GraphicCommandManager.h"
#include "GraphicResource.h"
#include "GraphicRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

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
			vector<GraphicTextureInfo> textures,
			bool useRecord,
			std::vector<int> records)
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
			cmd->recordID = records;
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(
			GraphicVertexInfo vertex, 
			RenderOperation operation, 
			ShaderProperty sproperty, 
			std::vector<GraphicTextureInfo> textures,
			bool useRecord,
			std::vector<int> records)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertex = vertex;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->textures = textures;
			cmd->useRecord = useRecord;
			cmd->recordID = records;
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(
			GraphicVertexInfo vertex,
			ShaderProperty sproperty,
			std::vector<GraphicTextureInfo> textures,
			bool useRecord,
			std::vector<int> records)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertex = vertex;
			RenderOperation operation;
			operation.depth = false;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->textures = textures;
			cmd->useRecord = useRecord;
			cmd->recordID = records;
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
			auto cmd = shared_ptr<GCMD_CreateRecord>(new GCMD_CreateRecord(name));
			GraphicCommandManager::AddRender(cmd);
		}
		void GraphicRenderer::StopRecord()
		{
			auto cmd = shared_ptr<GCMD_StopRecord>(new GCMD_StopRecord);
			GraphicCommandManager::AddRender(cmd);
		}
	}
}