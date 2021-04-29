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

		void GraphicRenderer::Render(GraphicVertexInfo v, RenderOperation o, RenderMatrix m, shared_ptr<ShaderProperty> s, std::vector<int> r)
		{
			auto cmd = shared_ptr<GDrawCMD>(new GDrawCMD());
			cmd->vertexData = GraphicResource::GetVertexData(v.info);
			cmd->operation = o;
			cmd->shaderProperty = s;
			cmd->shaderProperty->Add(MODEL_MATRIX, m.model);
			cmd->shaderProperty->Add(VIEW_MATRIX, m.view);
			cmd->shaderProperty->Add(PROJECTION_MARIX, m.projection);
			cmd->records = GetRecords(r);
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