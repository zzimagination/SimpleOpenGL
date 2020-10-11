#include "GraphicCommandManager.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<GraphicCommand*> GraphicCommandManager::resources;

		std::vector<GraphicCommand*> GraphicCommandManager::front_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::front_Setting;
		std::vector<GraphicCommand*> GraphicCommandManager::back_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::back_setting;


		void GraphicCommandManager::SwapCommands()
		{
			front_DrawCommands = back_DrawCommands;
			front_Setting = back_setting;
			back_DrawCommands.clear();
			back_setting.clear();

			resources.clear();
		}

		void GraphicCommandManager::AddVertexBuffer(shared_ptr<Vertex> data)
		{
			auto cmd = new  GVertexBufferCMD(data);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::AddTextureBuffer(Texture* data)
		{
			//auto cmd = new GraphicTextureBuffer(data);
			//back_AddResource.push_back(cmd);
		}

		void GraphicCommandManager::ClearVertexBuffer(shared_ptr<Vertex> data)
		{
			auto cmd = new  GVertexBufferClearCMD(data);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::ClearTextureBuffer(Texture* data)
		{
			//auto cmd = new  GraphicTextureBufferClear(data);
			//back_CollectResource.push_back(cmd);
		}

		void GraphicCommandManager::Draw(RenderBatch& batch)
		{
			auto vdata = GraphicDataCenter::GetVertexCommandData(batch.vertexData);
			auto cmd = new GDrawCMD(
				vdata, 
				batch.modelMatrix, 
				batch.viewMatrix, 
				batch.projectionMatrix, 
				batch.material->shader, 
				batch.material->shaderProperty);
			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::Clear(Color color, int mode)
		{
			auto cmd = new GClearCMD(color, mode);
			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::SetWireframe(bool enable)
		{
			auto cmd = new GWireframeCMD(enable);
			back_setting.push_back(cmd);
		}
	}
}
