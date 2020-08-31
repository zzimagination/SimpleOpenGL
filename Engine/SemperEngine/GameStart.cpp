#include "GameStart.h"
#include "GraphicShaderManager.h"
#include "DebugSystem.h"

namespace SemperEngine {
	void GameStart::Start()
	{
		ShaderManager::CompileShader();
	}
}
