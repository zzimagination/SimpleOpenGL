#include "GameStart.h"
#include "ShaderManager.h"
#include "DebugSystem.h"

namespace SemperEngine {
	void GameStart::Start()
	{
		ShaderManager::CompileShader();
	}
}
