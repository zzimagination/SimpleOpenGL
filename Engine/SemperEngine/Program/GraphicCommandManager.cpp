#include "GraphicCommandManager.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<GraphicCommand*> GraphicCommandManager::front_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::front_Setting;
		std::vector<GraphicCommand*> GraphicCommandManager::back_DrawCommands;
		std::vector<GraphicCommand*> GraphicCommandManager::back_setting;

		std::vector<GraphicCommand*> GraphicCommandManager::resources;

		void GraphicCommandManager::Render()
		{
			Excute(front_Setting);
			Excute(front_DrawCommands);
		}

		void GraphicCommandManager::Resource()
		{
			Excute(resources);
			resources.clear();
		}

		void GraphicCommandManager::SwapCommands()
		{
			front_DrawCommands = back_DrawCommands;
			front_Setting = back_setting;
			back_DrawCommands.clear();
			back_setting.clear();
		}

		void GraphicCommandManager::ClearCommands()
		{
			front_DrawCommands.clear();
			front_Setting.clear();
			back_DrawCommands.clear();
			back_setting.clear();
			resources.clear();
		}

		

		void GraphicCommandManager::AddVertexBuffer(GraphicDataInfo info)
		{
			auto cmd = new  GVertexBufferCMD(info);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::ClearVertexBuffer(GraphicDataInfo info)
		{
			auto cmd = new  GVertexBufferClearCMD(info);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::AddTextureBuffer(GraphicDataInfo info)
		{
			auto cmd = new GTextureBufferCMD(info);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::ClearTextureBuffer(GraphicDataInfo info)
		{
			auto cmd = new  GTextureBufferClearCMD(info);
			resources.push_back(cmd);
		}

		void GraphicCommandManager::Draw(
			GraphicVertexInfo vertex,
			RenderOperation operation,
			RenderMatrix matrix,
			ShaderProperty sproperty,
			vector<GraphicTextureInfo> textures)
		{
			auto cmd = new GDrawCMD();
			cmd->vertex = vertex;
			cmd->matrix = matrix;
			cmd->operation = operation;
			cmd->shaderProperty = sproperty;
			cmd->textures = textures;
			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::Clear(Color color, Graphic::ClearMode mode)
		{
			auto cmd = new GClearCMD(color, mode);
			back_DrawCommands.push_back(cmd);
		}

		void GraphicCommandManager::SetWireframe(bool enable)
		{
			auto cmd = new GWireframeCMD(enable);
			back_setting.push_back(cmd);
		}

		void GraphicCommandManager::Excute(std::vector<GraphicCommand*> &cmds)
		{
			for (int i = 0; i < cmds.size(); i++)
			{
				cmds[i]->Excute();
				delete cmds[i];
			}
		}
	}
}
