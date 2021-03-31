#ifndef __GRAPHICCMD_MANAGER__
#define __GRAPHICCMD_MANAGER__

#include <vector>
#include <memory>
#include <map>
#include "Graphic.h"
#include "GraphicData.h"
#include "GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicCommandManager
		{
		public:

			static std::vector<std::shared_ptr<GraphicCommand>> resources;

			static std::vector<std::shared_ptr<GraphicCommand>> front_DrawCommands;

			static std::vector<std::shared_ptr<GraphicCommand>> front_Setting;

			static std::vector<std::shared_ptr<GraphicCommand>> back_DrawCommands;

			static std::vector<std::shared_ptr<GraphicCommand>> back_setting;

		public:

			static void Render();

			static void Resource();

			static void SwapCommands();

			static void ClearCommands();

			static void AddResource(std::shared_ptr<GraphicCommand> command);

			static void AddRender(std::shared_ptr<GraphicCommand> command);

		private:

			static void Excute(std::vector<std::shared_ptr<GraphicCommand>>& cmds);
		};
	}
}

#endif // !GRAPHICCOMD_MANAGER
