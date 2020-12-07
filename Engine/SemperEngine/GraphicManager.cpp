#include "GraphicManager.h"
#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"

namespace SemperEngine
{
	namespace Core
	{
		void GraphicManager::Initialize()
		{
			GraphicDataCenter::Initialize();
			GraphicCommandManager::Resource();
		}
		void GraphicManager::BeforeLoopEnd()
		{
			GraphicCommandManager::Resource();
			GraphicCommandManager::SwapCommands();
		}
		void GraphicManager::LoopEnd()
		{
			GraphicCommandManager::Resource();
			GraphicCommandManager::SwapCommands();
		}
		void GraphicManager::Loop()
		{
			GraphicCommandManager::Render();
		}
		void GraphicManager::AfterLoop()
		{
			GraphicCommandManager::Resource();
		}
		void GraphicManager::Dispose()
		{
		}
	}
}