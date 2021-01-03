#include "GraphicManager.h"
#include "GraphicDataCenter.h"
#include "GraphicCommandManager.h"
#include "ShaderCompiler.h"

namespace SemperEngine
{
	namespace Core
	{
		void GraphicManager::Initialize()
		{
			ShaderCompiler::Compile();
			GraphicDataCenter::Initialize();
			GraphicCommandManager::Resource();
		}
		void GraphicManager::Render()
		{
			GraphicCommandManager::Render();
		}
		void GraphicManager::Resource()
		{
			GraphicCommandManager::Resource();
		}
		void GraphicManager::SwapCommands()
		{
			GraphicCommandManager::SwapCommands();
		}
		void GraphicManager::Dispose()
		{
			GraphicCommandManager::Resource();
		}
	}
}