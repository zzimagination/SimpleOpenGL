#include "GraphicSystem.h"
#include "GraphicResource.h"
#include "GraphicCommandManager.h"
#include "Graphic/GraphicRecordManager.h"
#include "ShaderCompiler.h"
#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void GraphicSystem::Initialize()
		{
			ShaderCompiler::Compile();
			GraphicResource::Initialize();
			GraphicCommandManager::Resource();
		}
		void GraphicSystem::Render()
		{
			GraphicCommandManager::Render();
			GraphicRecordManager::Clear();
		}
		void GraphicSystem::Resource()
		{
			GraphicCommandManager::Resource();
		}
		void GraphicSystem::SwapCommands()
		{
			GraphicRecordManager::Swap();
			GraphicCommandManager::SwapCommands();
		}
		void GraphicSystem::Dispose()
		{
			GraphicCommandManager::Resource();
		}
	}
}