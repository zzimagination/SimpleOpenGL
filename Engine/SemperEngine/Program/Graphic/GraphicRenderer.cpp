#include "GraphicRenderer.h"
#include "GraphicCommandManager.h"
#include "GraphicResource.h"
#include "GraphicRecordManager.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		void GraphicRenderer::Wireframe(bool enable)
		{
			auto cmd = shared_ptr<GCMD_Wireframe>(new GCMD_Wireframe(enable));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(
			GraphicVertexInfo vertex,
			RenderOperation operation,
			RenderMatrix matrix,
			ShaderProperty sproperty,
			vector<GraphicTextureInfo> textures,
			std::vector<int> records)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertexData = GraphicResource::GetVertexData(vertex.info);
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->shaderProperty.Add(MODEL_MATRIX, matrix.model);
			cmd->shaderProperty.Add(VIEW_MATRIX, matrix.view);
			cmd->shaderProperty.Add(PROJECTION_MARIX, matrix.projection);
			cmd->textureData = GetTextureDataList(textures);
			cmd->records = GetRecords(records);
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Render(
			GraphicVertexInfo vertex,
			RenderOperation operation,
			ShaderProperty sproperty,
			std::vector<GraphicTextureInfo> textures,
			std::vector<int> records)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertexData = GraphicResource::GetVertexData(vertex.info);
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->textureData = GetTextureDataList(textures);
			cmd->records = GetRecords(records);
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Clear(Color color, Graphic::ClearMode mode)
		{
			auto cmd = shared_ptr<GCMD_Clear>(new GCMD_Clear(color, mode));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::Clear(Color color)
		{
			auto cmd = shared_ptr<GCMD_Clear>(new GCMD_Clear(color, ClearColorDepth));
			GraphicCommandManager::AddRender(cmd);
		}

		void GraphicRenderer::DefaultFrameBuffer(int recordID)
		{
			auto r = GraphicRecordManager::GetRecord(recordID);
			auto cmd = shared_ptr<GCMD_DefaultFrameBuffer>(new GCMD_DefaultFrameBuffer(r));
			GraphicCommandManager::AddRender(cmd);
		}


		vector<GraphicTextureData*> GraphicRenderer::GetTextureDataList(vector<GraphicTextureInfo> textures)
		{
			vector<GraphicTextureData*> result;
			for (size_t i = 0; i < textures.size(); i++)
			{
				auto data = GraphicResource::GetTexture(textures[i].info);
				result.push_back(data);
			}
			return result;
		}

		std::vector<GraphicRecord*> GraphicRenderer::GetRecords(std::vector<int> idList)
		{
			vector<GraphicRecord*> result;
			for (size_t i = 0; i < idList.size(); i++)
			{
				auto record = GraphicRecordManager::GetRecord(idList[i]);
				result.push_back(record);
			}
			return result;
		}

	}
}