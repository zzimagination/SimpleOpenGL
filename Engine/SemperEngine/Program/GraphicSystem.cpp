#include "GraphicSystem.h"
#include "GraphicResource.h"
#include "GraphicCommandManager.h"
#include "ShaderCompiler.h"

namespace SemperEngine
{
	namespace Core
	{
		void GraphicSystem::Initialize()
		{
			ShaderCompiler::Compile();
			GraphicResource::Initialize();
			GraphicCommandManager::Resource();
		}
		void GraphicSystem::Render()
		{
			GraphicCommandManager::Render();
		}
		void GraphicSystem::Resource()
		{
			GraphicCommandManager::Resource();
		}
		void GraphicSystem::SwapCommands()
		{
			GraphicCommandManager::SwapCommands();
		}
		void GraphicSystem::Dispose()
		{
			GraphicCommandManager::Resource();
		}
	}
}