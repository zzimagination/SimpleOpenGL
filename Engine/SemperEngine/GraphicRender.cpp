#include "GraphicRender.h"
#include "RenderBatchManager.h"
#include "RenderBatch.h"
#include "GraphicRenderAPI.h"
#include "Texture.h"
#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"
#include "GLRendererAPI.h"
#include <iostream>
#include <map>
#include <malloc.h>

namespace SemperEngine
{
	namespace Core
	{
		void GraphicRender::Render()
		{
			auto commands = GraphicCommandManager::front_Setting;
			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->Excute();
				delete commands[i];
			}

			commands = Core::GraphicCommandManager::front_DrawCommands;
			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->Excute();
				delete commands[i];
			}
		}

		void GraphicRender::Resource()
		{
			auto commands = Core::GraphicCommandManager::resources;
			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->Excute();
				delete commands[i];
			}
		}
	}
}