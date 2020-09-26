#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<GraphicCommand*> GraphicCommandManager::front_AddResource;
		std::vector<GraphicCommand*> GraphicCommandManager::front_CollectResource;
		std::vector<GraphicCommand*> GraphicCommandManager::front_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::back_AddResource;
		std::vector<GraphicCommand*> GraphicCommandManager::back_CollectResource;
		std::vector<GraphicCommand*> GraphicCommandManager::back_DrawCommands;


		void GraphicCommandManager::SwapCommands()
		{
			front_CollectResource = back_CollectResource;
			front_AddResource = back_AddResource;
			front_DrawCommands = back_DrawCommands;
			back_AddResource.clear();
			back_CollectResource.clear();
			back_DrawCommands.clear();
		}

		void GraphicCommandManager::AddVertexBuffer(RenderVertexData * data)
		{
			auto cmd = new  GraphicVertexBuffer(data);
			back_AddResource.push_back(cmd);
		}

		void GraphicCommandManager::AddTextureBuffer(Texture * data)
		{
			auto cmd = new GraphicTextureBuffer(data);
			back_AddResource.push_back(cmd);
		}

		void GraphicCommandManager::ClearVertexBuffer(RenderVertexData * data)
		{
			auto cmd = new  GraphicVertexBufferClear(data);
			back_CollectResource.push_back(cmd);
		}

		void GraphicCommandManager::ClearTextureBuffer(Texture * data)
		{
			auto cmd = new  GraphicTextureBufferClear(data);
			back_CollectResource.push_back(cmd);
		}

		void GraphicCommandManager::Draw(RenderBatch  batch)
		{
			auto cmd = new  GraphicDraw(batch);
			back_DrawCommands.push_back(cmd);
		}
	}
}
