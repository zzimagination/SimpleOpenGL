#include "GraphicCommandManager.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::vector<std::shared_ptr<GraphicCommand>> GraphicCommandManager::front_DrawCommands;
		std::vector<std::shared_ptr<GraphicCommand>> GraphicCommandManager::front_Setting;
		std::vector<std::shared_ptr<GraphicCommand>> GraphicCommandManager::back_DrawCommands;
		std::vector<std::shared_ptr<GraphicCommand>> GraphicCommandManager::back_setting;

		std::vector<std::shared_ptr<GraphicCommand>> GraphicCommandManager::resources;

		void GraphicCommandManager::Render()
		{
			Excute(front_Setting);
			Excute(front_DrawCommands);
			front_Setting.clear();
			front_DrawCommands.clear();
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

		void GraphicCommandManager::AddResource(std::shared_ptr<GraphicCommand> command)
		{
			resources.push_back(command);
		}

		void GraphicCommandManager::AddRender(std::shared_ptr<GraphicCommand> command)
		{
			back_DrawCommands.push_back(command);
		}

		void GraphicCommandManager::Excute(std::vector<std::shared_ptr<GraphicCommand>> &cmds)
		{
			for (int i = 0; i < cmds.size(); i++)
			{
				cmds[i]->Excute();
			}
		}
	}
}
