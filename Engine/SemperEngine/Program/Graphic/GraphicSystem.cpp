#include "GraphicSystem.h"
#include "GraphicResource.h"
#include "GraphicCommandManager.h"
#include "GraphicRecordManager.h"
#include "GraphicShaderManager.h"
#include "ShaderCompiler.h"
#include <memory>

namespace Semper
{
	namespace Core
	{
		using namespace std;

		void GraphicSystem::Initialize()
		{
			GraphicShaderManager::Initialize();
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