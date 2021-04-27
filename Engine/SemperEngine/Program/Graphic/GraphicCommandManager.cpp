#include "GraphicCommandManager.h"
#include "GraphicResource.h"

namespace Semper
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
			Execute(front_Setting);
			Execute(front_DrawCommands);
			front_Setting.clear();
			front_DrawCommands.clear();
		}

		void GraphicCommandManager::Resource()
		{
			Execute(resources);
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

		void GraphicCommandManager::Execute(std::vector<std::shared_ptr<GraphicCommand>> &cmds)
		{
			for (int i = 0; i < cmds.size(); i++)
			{
				cmds[i]->Execute();
			}
		}
	}
}
