#include "GraphicRender.h"
#include "RenderBatchManager.h"
#include "RenderBatch.h"
#include "GraphicRenderDraw.h"
#include "Texture.h"
#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine {

	void GraphicRender::Render()
	{
		auto commands = Core::GraphicCommandManager::front_CollectResource;
		for (int i = 0; i < commands.size(); i++)
		{
			commands[i]->Excute();
			delete commands[i];
		}

		commands = Core::GraphicCommandManager::front_AddResource;
		for (int i = 0; i < commands.size(); i++)
		{
			commands[i]->Excute();
			delete commands[i];
		}

		GraphicRenderDraw::SetClear(ClearMode::Color | ClearMode::Depth, Vector4(0.0f, 0.0f, 0.0f, 1));

		commands = Core::GraphicCommandManager::front_DrawCommands;
		for (int i = 0; i < commands.size(); i++)
		{
			commands[i]->Excute();
			delete commands[i];
		}


		//GraphicRenderDraw::TestRender();
	}
}