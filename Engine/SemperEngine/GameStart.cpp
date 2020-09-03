#include "GameStart.h"
#include "GraphicShaderManager.h"
#include "WorldInitializer.h"
#include "DebugSystem.h"


namespace SemperEngine {
	void GameStart::Start()
	{
		ShaderManager::CompileShader();
		Core::WorldInitializer::Initialize();
	}
}
